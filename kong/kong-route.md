
print(debug.traceback())

## 生成规则
```
2022/01/13 16:35:06 [notice] 6824#0: [lua] router.lua:1478: new(): stack traceback:
        /usr/local/share/lua/5.1/kong/router.lua:1478: in function 'new'
        /usr/local/share/lua/5.1/kong/runloop/handler.lua:788: in function 'build_router'
        /usr/local/share/lua/5.1/kong/init.lua:620: in function 'init'
        init_by_lua:3: in main chunk
```
在 init_by_lua_block 中 kong.init() ， runloop.build_router 中生成路由表


router.new()  的参数为 {router, service} 数组： 
```
{
        service = {
            ws_id = 378fc560-d392-4ee3-8e98-a5adde367bb4
            id = 17599055-4385-4da7-ac1e-80e3e0453f34
            protocol = http
            retries = 5
            port = 80
            connect_timeout = 60000
            updated_at = 1641546941
            created_at = 1641546941
            host = httpbin.org
            name = example.service
            write_timeout = 60000
            read_timeout = 60000
        }
        route = {
            ws_id = 378fc560-d392-4ee3-8e98-a5adde367bb4
            protocols = {
                1 = http
                2 = https
            }
            id = 363b5e63-119e-40d1-9066-7b1c55c83883
            request_buffering = true
            response_buffering = true
            service = {
                id = 17599055-4385-4da7-ac1e-80e3e0453f34
            }
            preserve_host = false
            strip_path = false
            regex_priority = 0
            updated_at = 1641973449
            paths = {
                1 = /ip
                2 = /test/haha
            }
            methods = {
                1 = GET
            }
            created_at = 1641973449
            https_redirect_status_code = 426
            path_handling = v0
        }
    }
```
```
{
        service = {
            ws_id = 378fc560-d392-4ee3-8e98-a5adde367bb4
            id = 17599055-4385-4da7-ac1e-80e3e0453f34
            protocol = http
            retries = 5
            port = 80
            connect_timeout = 60000
            updated_at = 1641546941
            created_at = 1641546941
            host = httpbin.org
            name = example.service
            write_timeout = 60000
            read_timeout = 60000
        }
        route = {
            ws_id = 378fc560-d392-4ee3-8e98-a5adde367bb4
            protocols = {
                1 = http
                2 = https
            }
            id = e099c070-4449-4fe7-b4f9-23f28125f78c
            request_buffering = true
            response_buffering = true
            service = {
                id = 17599055-4385-4da7-ac1e-80e3e0453f34
            }
            preserve_host = false
            strip_path = false
            regex_priority = 0
            updated_at = 1641546988
            paths = {
                1 = /base64
            }
            created_at = 1641546988
            https_redirect_status_code = 426
            path_handling = v0
        }
    }

```

### 对路由进行整理，保存在 local marshalled_routes = {}

```
1 = {
            upstream_url_t = {
                path = /
                type = name
                host = httpbin.org
                port = 80
                scheme = http
            }
            hosts = {
            }
            type = http
            snis = {
            }
            methods = {
                GET = true
            }
            sources = {
            }
            destinations = {
            }
            preserve_host = false
            strip_uri = false
            match_rules = 24
            match_weight = 2
            submatch_weight = 0
            max_uri_length = 3
            uris = {
                1 = {
                    is_prefix = true
                    value = /ip
                }
                /ip = {
                    is_prefix = true
                    value = /ip
                }
            }
            route = {
                protocols = {
                    1 = http
                    2 = https
                }
                regex_priority = 0
                paths = {
                    1 = /test/haha
                }
                strip_path = false
                -- ...
                methods = {
                    1 = GET
                }
                service = {
                    id = 17599055-4385-4da7-ac1e-80e3e0453f34
                }
                -- ...
            }
            service = {
                -- ....
            }
            headers = {
            }
        }

```

uri 中没有正则字符串，is_prefix = true， 如果是正则， is_regex = true,
host 匹配
```
hosts = {
                1 = {
                    regex = .+\.test\.com(?::\d+)?$
                    wildcard = true
                    value = *.test.com
                }
                2 = {
                    value = www.haha.com     --普通字符串
                }
                www.haha.com = www.haha.com
            }
```
如果是正则，wildcard = true，

### categories
 -- all routes grouped by the category they belong to, to reduce
  -- iterations over sets of routes per request

规则类型 7种 
```
local MATCH_RULES = {
  HOST            = 0x00000040,
  HEADER          = 0x00000020,
  URI             = 0x00000010,
  METHOD          = 0x00000008,
  SNI             = 0x00000004,
  SRC             = 0x00000002,
  DST             = 0x00000001,
}
```
一共有 127 种组合

```
    {
        88 = {
            routes_by_hosts = {
                *.test.com = { ...... }
                www.haha.com = { ...... }
            }
            routes_by_headers = {
            }
            routes_by_uris = {
                /anything/[1-9][0-9] = { ...... }
            }
            routes_by_methods = {
                POST = { ...... }
                GET = { ...... }
            }
            routes_by_sources = {
            }
            routes_by_destinations = {
            }
            match_weight = 3
            all = {
                1 = { ...... }
            }
            routes_by_sni = {
            }
        }
        24 = {
            routes_by_hosts = {
            }
            routes_by_headers = {
            }
            routes_by_uris = {
                /ip = { ...... }
                /test/haha = { ...... }
            }
            routes_by_methods = {
                GET = { ...... }
            }
            routes_by_sources = {
            }
            routes_by_destinations = {
            }
            match_weight = 2
            all = {
                1 = { ...... }
                2 = { ...... }
            }
            routes_by_sni = {
            }
        }
    }
```


### categories_weight_sorted = {}
 -- a sorted array of all categories bits (from the most significant
  -- matching-wise, to the least significant)

根据weight 排序
```
category_bit = category_bit,
match_weight = category.match_weight,
```
```
{
        1 = {
            category_bit = 88
            match_weight = 3
        }
        2 = {
            category_bit = 24
            match_weight = 2
        }
        3 = {
            category_bit = 16
            match_weight = 1
        }
    }
```


### categories_lookup = {}
  -- a lookup array to get the category_idx from a category_bit. The
  -- idx will be a categories_weight_sorted index

根据 category_bit 查 category_idx
```
{
        88 = 1
        16 = 3
        24 = 2
    }
```

-- when hash lookup in plain_indexes fails, those are arrays
  -- of regexes for `uris` as prefixes and `hosts` as wildcards
  -- or IP ranges comparison functions

###  prefix_uris
-- will be sorted by length
```
{
        1 = {
            is_prefix = true
            value = /test/haha
        }
        2 = {
            is_prefix = true
            value = /base64
        }
        3 = {
            is_prefix = true
            value = /ip
        }
    }
```

### plain_indexes = {}

```
{
        snis = {
        }
        headers = {
        }
        methods = {
            POST = true
            GET = true
        }
        sources = {
        }
        destinations = {
        }
        uris = {
            /base64 = true
            /ip = true
            /test/haha = true
        }
        hosts = {
            www.haha.com = true
        }
    }
```
















## 路由匹配流程
```
2022/01/10 10:44:45 [error] 2543#0: *151 [kong] router.lua:1467 stack traceback:
        /usr/local/share/lua/5.1/kong/router.lua:1467: in function 'find_route'
        /usr/local/share/lua/5.1/kong/router.lua:1880: in function 'exec'
        /usr/local/share/lua/5.1/kong/runloop/handler.lua:1207: in function 'before'
        /usr/local/share/lua/5.1/kong/init.lua:905: in function 'access'
        access_by_lua(nginx-kong.conf:152):2: in main chunk, client: 192.168.56.1, server: kong, request: "GET /base64/SFRUUEJJTiBpcyBhd2Vzb21l HTTP/1.1", host: "192.168.56.101:8000"
```

在 find_route 中， 
1. 保存变量到 ctx， （req_method,req_uri等等）
2. 如果 req_host 不是 “”， 去掉port （host:port）
3. 从缓存里面查询匹配结果.没有则继续
4. plain_indexes 内容 ```
        {
        destinations = {
        }
        snis = {
        }
        hosts = {
        }
        headers = {
        }
        uris = {
            /ip = true
            /base64 = true
        }
        methods = {
            GET = true
        }
        sources = {
        }
    }

```  
* 根据 plain_indexes 生成 req_category = MATCH_RULES.METHOD | MATCH_RULES.URI
首先匹配精确域名，没有的话再匹配泛域名。匹配泛域名时需要遍历 wildcard_hosts 。
匹配uri， 首先匹配正则uri （存储在 regex_uris），如果没有，再从 plain_indexes 中匹配精确uri。
。。。
* 根据 req_category 在 categories_lookup 中找到  category_idx， 如果没有，则 category_idx =1，遍历查找。 比如 categories_lookup = {88，24， 16}， 如果 req_category = 64， 或 40， category_idx = 1。 如果 req_category=24， category_idx = 2
* 根据 category_idx 在 categories_weight_sorted 



* reduce：


* match_route: 根据 route_t.match_rules 规则，执行 matchers 中对应的函数，如果 route_t.match_rules 不是 1，2，4，8，16，32，64等，则依次执行对应的函数，并缓存。
比如method 匹配， 就是查找在 route_t.methods 中是否有 ctx.req_method。 
查找 header 时， 时间复杂度 O(M*N)
匹配 uri， 判断是否是正则，  直接匹配或者前缀匹配，使用 string.find(),   

* 生成 match_t， 缓存




[zb调试OpenResty](http://notebook.kulchenko.com/zerobrane/debugging-openresty-nginx-lua-scripts-with-zerobrane-studio)


plain_indexes
categories_lookup
category

curl 设置 sni  
curl --resolve 'channel.30.cn:443:4.36.9.7' -i https://channel.30.cn/ -H "host:channel.30.cn" -k -vvl