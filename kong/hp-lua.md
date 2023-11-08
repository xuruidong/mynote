
## 使用`#`替换`string.len`
why ?

## 不使用 ipairs

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


## links
[luajit官方性能优化指南和注解](https://www.cnblogs.com/zwywilliam/p/5992737.html)  
