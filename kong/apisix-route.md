

[Redis radix tree源码解析](https://my.oschina.net/u/1464083/blog/3039042)  
[路由查找之Radix Tree](http://www.noobyard.com/article/p-pxbqpmqt-gn.html)  


[Ternary Search Tree](https://www.geeksforgeeks.org/ternary-search-tree/)  


[APISIX高级路由之通过Body参数转发请求](https://zhang.ge/5157.html)  
## 路由初始化
```
init_worker_by_lua_block {
    apisix.http_init_worker()
}
```

apisix.http_init_worker()
    apisix.router.http_init_worker()
        attach_http_router_common_methods(router_http)
        router_http.init_worker(filter)






## 重建路由
路由匹配时会检查版本号， 如果版本号不一致，会重建路由

create_radixtree_uri_router(user_routes.values, uri_routes, false)
uri_router： 当前的路由？ 这个最后是 radix.new 的参数
user_routes.values:  用户配置的路由 
```
values = {
            1 = {
                clean_handlers = {
                }
                value = {
                    update_time = 1642491304
                    status = 1
                    methods = {
                        1 = GET
                    }
                    host = example.com
                    priority = 0
                    upstream = {
                        scheme = http
                        pass_host = pass
                        nodes = { ...... }
                        parent = { ...... }
                        type = roundrobin
                        hash_on = vars
                    }
                    create_time = 1642491304
                    uri = /anything/*
                    id = 1
                }
                update_count = 0
                has_domain = true
                orig_modifiedIndex = 272
                modifiedIndex = 272
                createdIndex = 272
                key = /apisix/routes/1
            }
        }
```

生成新的 uri_routes：
```
{
    1 = {
        handler = function: 0x7f4555b0d360
        paths = /anything/*
        priority = 0
        methods = {
            1 = GET
        }
        hosts = example.com
    }
    2 = {
        handler = function: 0x7f4555612868
        paths = /ip
        priority = 0
        methods = {
            1 = GET
            2 = POST
            3 = PUT
        }
        hosts = www.abc.com
    }
    3 = {
        handler = function: 0x7f4555644ed0
        paths = /user-agent
        priority = 0
        methods = {
            1 = GET
            2 = POST
            3 = HEAD
            4 = OPTIONS
        }
    }
    4 = {
        handler = function: 0x7f4555640ed8
        paths = /abc*
        priority = 0
        methods = {
            1 = GET
            2 = POST
            3 = PUT
            4 = HEAD
            5 = OPTIONS
        }
    }
    5 = {
        handler = function: 0x7f4555733278
        paths = /var/*
        priority = 0
        methods = {
            1 = GET
            2 = POST
            3 = PUT
            4 = DELETE
            5 = PATCH
            6 = HEAD
            7 = OPTIONS
            8 = CONNECT
            9 = TRACE
        }
        vars = {
            1 = {
                1 = http_host
                2 = ==
                3 = iresty.com
            }
        }
    }
}
```
```
handler = function (api_ctx, match_opts)
                    api_ctx.matched_params = nil
                    api_ctx.matched_route = route
                    api_ctx.curr_req_matched = match_opts.matched
                end
```
然后执行 radixtree.new(uri_routes) 创建路由




### 带filter 的情况



## 路由匹配

apisix.http_access_phase() :: router.router_http.match(api_ctx)  路由匹配入口  

```
access_by_lua_block {
    apisix.http_access_phase()
}
```


判断是否要重新生成 uri_router
apisix.http.route.match_uri(uri_router, match_opts, api_ctx)
* 根据当前请求，生成 match_opts
首先将 match_opts 清空（为了复用match_opts， 这样做是因为高效），将 request_method,host,var等变量填充到 match_opts， 执行
uri_router:dispatch(api_ctx.var.uri, match_opts, api_ctx, match_opts) 进行路由匹配。
match_opts:  
```
{
        vars = {
            _request = cdata<void *>: 0x021abd60
            _cache = {
                uri = /anything/foo
                request_method = GET
                real_request_uri = //anything/foo?arg=10
                request_uri = /anything/foo?arg=10
                host = example.com
                remote_addr = 192.168.56.1
            }
        }
        host = example.com
        remote_addr = 192.168.56.1
        method = GET
        matched = {
        }
    }
	host = example.com
    remote_addr = 192.168.56.1
    method = GET
    matched = {
    }
}
```
* 执行uri_router:dispatch(api_ctx.var.uri, match_opts, api_ctx, match_opts) 进行路由匹配
radixtree 的 dispatch 函数。
```
/usr/local/apisix//deps/share/lua/5.1/resty/radixtree.lua:558: in function 'match_route_opts'
/usr/local/apisix//deps/share/lua/5.1/resty/radixtree.lua:689: in function 'match_route'
/usr/local/apisix//deps/share/lua/5.1/resty/radixtree.lua:757: in function 'dispatch'
/usr/local/apisix/apisix/http/route.lua:159: in function 'match'
/usr/local/apisix/apisix/init.lua:386: in function 'http_access_phase'
access_by_lua(nginx.conf:269):2: in main chunk, 
```

执行 match_route() 
* 绝对路径匹配 放到 self.hash_path 表中 (在 lua-resty-radixtree v0.5 之前，直接使用 radix.radix_tree_search)
* 前缀路径匹配 放到 self.match_data

match_route_opts:  
* 使用位图匹配请求方法method
* 匹配 remote_addr
* 匹配 host 时，要遍历 route.hosts, （match_host），如果是精确域名，返回 route_host== request_host， 如果是泛域名匹配， 使用 memcmp
* route.vars 匹配 ？？？
* 执行 route.filter_fun

```
local hosts = route.hosts
local host = opts.host
if host then
    local len = #hosts
    for i = 1, len, 2 do
        if match_host(hosts[i], hosts[i + 1], host) then
            if opts_matched_exists then
                if hosts[i] then
                    opts.matched._host = "*" .. hosts[i + 1]
                else
                    opts.matched._host = opts.host
                end
            end
            matched = true
            break
        end
    end
end
```

```
if route.vars then
    local ok, err = route.vars:eval(opts.vars, opts)
    if not ok then
        if ok == nil then
            log_err("failed to eval expression: ", err)
        end

        return false
    end
end
```
```
1 = {
    path_org = /var/*
    vars = {
        rule = {
            exprs = {
                1 = {
                    op = ==
                    reverse = false
                    l_v = http_host
                    r_v = iresty.com
                }
            }
            logic_op = AND
        }
    }
    path = /var/
    priority = 0
    path_op = <=
    method = 511
    handler = function: 0x7fab552cd158
    param = false
}
```


[正则匹配](https://apisix.apache.org/zh/docs/apisix/FAQ/#route-%E7%9A%84-uri-%E5%A6%82%E4%BD%95%E8%BF%9B%E8%A1%8C%E6%AD%A3%E5%88%99%E5%8C%B9%E9%85%8D)  
