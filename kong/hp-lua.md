
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
