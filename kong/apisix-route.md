

[Redis radix tree源码解析](https://my.oschina.net/u/1464083/blog/3039042)  
[路由查找之Radix Tree](http://www.noobyard.com/article/p-pxbqpmqt-gn.html)  


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

生成新的 uri_router：
```
{
        1 = {
            handler = function: 0x7fe6eca44310
            paths = /anything/*
            methods = {
                1 = GET
            }
            hosts = example.com
            priority = 0
        }
    }
```





### 带filter 的情况



## 路由匹配

apisix.http_access_phase() :: router.router_http.match(api_ctx)  路由匹配入口  

```
access_by_lua_block {
    apisix.http_access_phase()
}
```


apisix.http.route.match_uri(uri_router, match_opts, api_ctx)
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
```
radixtree 的 dispatch 函数。



[正则匹配](https://apisix.apache.org/zh/docs/apisix/FAQ/#route-%E7%9A%84-uri-%E5%A6%82%E4%BD%95%E8%BF%9B%E8%A1%8C%E6%AD%A3%E5%88%99%E5%8C%B9%E9%85%8D)  
