# C++ lambda 表达式


[C++ STL关联式容器自定义排序规则](http://c.biancheng.net/view/7213.html)  

## 从 sort 开始
### 内置类型容器排序
#### 默认行为
```
int main()
{
    vector<int> testv = {115,19,18,54,108,540,90,80,360,720};
    sort(testv.begin(), testv.end());
    utils::vector_print(testv);
}
```

输出：18,19,54,80,90,108,115,360,540,720

#### 降序
```
int main()
{
    vector<int> testv = {115,19,18,54,108,540,90,80,360,720};
    sort(testv.begin(), testv.end()，greater<int>());
    utils::vector_print(testv);
}
```
输出：720,540,360,115,108,90,80,54,19,18

#### 自定义比较函数
```
bool mycomp(int i, int j) {
    return (i < j);
}

int main()
{
    vector<int> testv = {115,19,18,54,108,540,90,80,360,720};
    sort(testv.begin(), testv.end(), mycomp);
    utils::vector_print(testv);
}
```
如果自定义比较函数中是 return (i < j), 就是升序，i>j 就是降序

#### 函数对象的方式
```
class mycomp2 {
public:
    bool operator() (int i, int j) {
        return (i < j);
    }
};
```

### 自定义类型容器排序

结构定义：
```
struct cls_demo{
private:
public:
    int va;
    int vb;

    cls_demo(int a, int b){
        va = a;
        vb = b;
    }

    void print() {
        cout<<"va="<<va<<",vb="<<vb<<endl;
    }
#if 0
    bool operator < (cls_demo &c1) const {
        return va < c1.va;
    }
#endif
};
```

#### “<" 重载
要使用sort 排序，就要实现 "<" 重载
```
bool operator < (cls_demo &c1) const {
        return va < c1.va;
    }
```

#### 自定义比较函数

#### 函数对象的方式
```
class mycomp2 {
public:
    bool operator() (int i, int j) {
        return (i < j);
    }
};
```

#### 使用lambda 表达式
```
cls_demo c1(1,100);
    cls_demo c2(2, 99);

    vector<cls_demo> v;
    v.push_back(c1);
    v.push_back(c2);
    sort(v.begin(), v.end(), [](cls_demo &c1, cls_demo &c2)->bool{
            return c1.va < c2.va;
         });
    for(auto &e: v) {
        e.print();
    }
```
输出： 
```
va=1,vb=100
va=2,vb=99
```


## find
find() 函数的底层实现，其实就是用==运算符将 val 和 [first, last) 区域内的元素逐个进行比对。这也就意味着，[first, last) 区域内的元素必须支持==运算符。  

在一个vector 中，查找元素成员变量值为 v 的元素


## lower_bound


## priority_queue
