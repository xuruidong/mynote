
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


## links
[luajit官方性能优化指南和注解](https://www.cnblogs.com/zwywilliam/p/5992737.html)  