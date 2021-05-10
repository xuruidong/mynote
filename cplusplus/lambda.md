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
find() 函数的底层实现，其实就是用`==`运算符将 val 和 [first, last) 区域内的元素逐个进行比对。这也就意味着，[first, last) 区域内的元素必须支持`==`运算符。  

在一个vector 中，查找元素成员变量值为 v 的元素

==加背景==
## lower_bound

### 从一个降序数列中找到最后一个大于等于目标值的对象  

50，40，30，20，10
找25  ，返回30  


### 从一个非降序数列中找到最后一个大于等于目标值的对象
1，2，3，3，3，3，4，5  
找到最后一个3


## upper_bound
[](https://en.cppreference.com/w/cpp/algorithm/upper_bound)  
upper_bound() 函数定义在`<algorithm>`头文件中，用于在指定范围内查找大于目标值的第一个元素。这是默认行为， 默认的查找规则使用`<`做比较，所以更加准确的作用定义为：用于在指定范围内查找违反比较规则的第一个元素。  
comp 作用自定义查找规则，此参数可接收一个包含 2 个形参（第一个形参值始终为 target_val）且返回值为 bool 类型的函数，可以是普通函数，也可以是函数对象。（即 comp(target_val, element_val) == true, 就不违反比较规则）。

另外，由于 upper_bound() 底层实现采用的是二分查找的方式，因此该函数仅适用于“已排好序”的序列。<font color=red>注意，这里所说的“已排好序”，并不要求数据完全按照某个排序规则进行升序或降序排序，而仅仅要求 [first, last) 区域内所有令 !(element < val)（或者 !comp(val, element）成立的元素都位于不成立元素的前面（其中 element 为指定范围内的元素）。</font> 在网站上的内容，写错了!!!
这是 cppreference.com 原文：
The range [first, last) must be partitioned with respect to the expression !(value < element) or !comp(value, element), i.e., all elements for which the expression is true must precede all elements for which the expression is false. A fully-sorted range meets this criterion.


总结为：  
* 比较规则的形式为 value < element  或  comp(value, element)  
* “排序数组” 需要满足比较规则成立的元素放后面，比较规则不成立的放前面

示例1：  
```
void upper_bound_test()
{
    vector<int> nums = {5,4,3,2,1};
    vector<int>::iterator iter = upper_bound(nums.begin(), nums.end(), 3, greater<int>());
    for(; iter != nums.end(); ++iter) {
        cout<<*iter<<" ";
    }
    cout<<endl;  // 2, 1

    nums = {1,2,3,4,5};
    iter = upper_bound(nums.begin(), nums.end(), 3, greater<int>());
    for(; iter != nums.end(); ++iter) {
        cout<<*iter<<" ";
    }
    cout<<endl; // null


}
```
{5,4,3,2,1} 满足“排序数组”的规则， 3>element 的放后面， !(3>element) 的放前面  





## priority_queue
