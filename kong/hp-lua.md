
## 使用`#`替换`string.len`
因为`string.len()`需要先查找 string 再找其下的 len，再传参再调用，至少需要4条 lua vm bytecode；而`#`直接被翻译为`LEN`指令，一条指令就可以算出来。 [来源](https://segmentfault.com/q/1010000007132888)  
https://github.com/apache/apisix/pull/8751  


## ~~不使用 ipairs~~ 

```
for i, span in ipairs(tab) do

end
```
替换为
```
for i = 1, #tab do

end
```

## ngx.re.match
使用 ngx.re.match 替换 string.match， 
注意 flag， i,j 。 Using the i flag for case insensitive matching should be faster.  


## table length? 
不要手动计算 table 长度，来试图加速 `table.insert` 


## string.find
`str:find("x", 1, true)` is better than normal `str:find("x")`  
The 3rd `true` argument of `string:find` is for plain text  
https://github.com/Kong/kong/pull/11918  


## string.buffer 替换 table.concat
https://github.com/Kong/kong/pull/11304

## links
[luajit官方性能优化指南和注解](https://www.cnblogs.com/zwywilliam/p/5992737.html)  

## Local variables
The access to [local variables](https://www.lua.org/pil/4.2.html#:~:text=Local%20variables%20help%20you%20avoid,local%20variable%20declarations%20as%20statements.) is faster than to global ones.
