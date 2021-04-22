
# 数组、链表、跳表

## 数组降龙十八掌

哈希表法，双指针法，单调栈， 单调队列
### 哈希表法
[两数之和](https://leetcode-cn.com/problems/two-sum/)

### 双指针法
#### 头尾指针
[盛最多水的容器](https://leetcode-cn.com/problems/container-with-most-water/)
[三数之和](https://leetcode-cn.com/problems/3sum/)

#### 快慢指针
[移动零](https://leetcode-cn.com/problems/move-zeroes/)

### 非波拉契数列
[爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)


### 辅助栈、队列
[有效的括号](https://leetcode-cn.com/problems/valid-parentheses/)

### 二分
排序的数组，或者部分有序


### 单调栈， 单调队列
[滑动窗口最大值](https://leetcode-cn.com/problems/sliding-window-maximum/)

### 滑动窗口



---

## 链表
注意边界，空，单节点， 尾部  
快慢指针

### 单向链表

### 双向链表

### 循环链表


# skip list
Redis 中使用了跳表。  
链表的查找时间复杂度为 O(n)，如何提高链表的查找效率？ 空间换时间，增加索引。


## 练习步骤
1. 5-10分钟：读题与思考
2. 有思路：写代码；没思路：看题解
3. 默写背诵
4. 自己写

看题解讨论，
看国际站的题解讨论，按照MOST VOTES


## 数组：
### 双指针法，快慢指针:  
#### 移动零
暴力解法
一般方法
最优解法


### 快慢指针+保留逻辑
[删除有序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)  
[删除有序数组中的重复项2](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/)  

### 头尾指针，左右边界
#### 盛水最多的容器
暴力解法

#### 两数之和
暴力解法： 注意的问题--内层循环的开始位置
HASH表解法: 两种方法
不能使用左右指针逼近的方法，排序后索引发生变化


++i 比 i++ 快！！！

### 非波拉契数列
#### 爬楼梯问题
无法暴力求解  
递归：
动态规划：  

----

[自顶向下的编程方式](https://markhneedham.com/blog/2008/09/15/clean-code-book-review/)
[自顶向下编程的 LeetCode 例题](https://leetcode-cn.com/problems/valid-palindrome/)
栈，双指针


## 第03课丨01数组、链表、跳表的基本实现和特性  
[Linked List 的标准实现代码](https://www.geeksforgeeks.org/implementing-a-linked-list-in-java-using-class/)  
[LRU 缓存机制](https://leetcode-cn.com/problems/lru-cache/)  
[redis skiplist](https://redisbook.readthedocs.io/en/latest/internal-datastruct/skiplist.html)  
[跳跃表、为啥 Redis 使用跳表（Skip List）而不是使用 Red-Black？](https://www.zhihu.com/question/20202931)  

两数之和题目： https://leetcode-cn.com/problems/two-sum/
Array 实战题目
    • https://leetcode-cn.com/problems/container-with-most-water/
    • https://leetcode-cn.com/problems/move-zeroes/
    • https://leetcode.com/problems/climbing-stairs/
    • https://leetcode-cn.com/problems/3sum/ (高频老题）
Linked List 实战题目
    • https://leetcode.com/problems/reverse-linked-list/
* [两两交换链表中的节点](https://leetcode.com/problems/swap-nodes-in-pairs)  递归、迭代  
* [环形链表](https://leetcode.com/problems/linked-list-cycle)  
* [环形链表2](https://leetcode.com/problems/linked-list-cycle-ii)  
    你是否可以使用 O(1) 空间解决此题？  
    两种方法 
    • https://leetcode.com/problems/reverse-nodes-in-k-group/
课后作业
* [删除有序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)  
    • https://leetcode-cn.com/problems/rotate-array/
    • https://leetcode-cn.com/problems/merge-two-sorted-lists/
    边界， [] [1], [1] [], [] []  
    • https://leetcode-cn.com/problems/merge-sorted-array/
    • https://leetcode-cn.com/problems/two-sum/
    • https://leetcode-cn.com/problems/move-zeroes/
* [plus-one](https://leetcode-cn.com/problems/plus-one/)


## 第04课丨01栈和队列的实现与特性
    • [Java 的 PriorityQueue 文档](https://docs.oracle.com/javase/10/docs/api/java/util/PriorityQueue.html)
    • [Java 的 Stack 源码](http://developer.classpath.org/doc/java/util/Stack-source.html)
    • [Java 的 Queue 源码](http://fuseyism.com/classpath/doc/java/util/Queue-source.html)
    • [Python 的 heapq](http://docs.python.org/2/library/heapq.html)
    • [高性能的 container 库](http://docs.python.org/2/library/collections.html)


预习题目
    • https://leetcode-cn.com/problems/valid-parentheses/
    • https://leetcode-cn.com/problems/min-stack/
实战题目
    • https://leetcode-cn.com/problems/largest-rectangle-in-histogram
    • https://leetcode-cn.com/problems/sliding-window-maximum
课后作业
    • 用 add first 或 add last 这套新的 API 改写 Deque 的代码
    • 分析 Queue 和 Priority Queue 的源码
    • https://leetcode.com/problems/design-circular-deque
    • https://leetcode.com/problems/trapping-rain-water/

第05课丨01哈希表、映射、集合的实现与特性
实战题目 / 课后作业
    • https://leetcode-cn.com/problems/valid-anagram/description/
    • https://leetcode-cn.com/problems/group-anagrams/
    • https://leetcode-cn.com/problems/two-sum/description/
参考链接  
    • [养成收藏精选代码的习惯（示例）](http://shimo.im/docs/R6g9WJV89QkHrDhr)


第06课丨01树、二叉树、二叉搜索树的实现和特性
[二叉搜索树 Demo](https://visualgo.net/zh/bst?slide=1) 

实战题目 / 课后作业  
*[二叉树中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)  
*[二叉树的前序遍历](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/)  
    • https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/
    • https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/
    • https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/


第07课丨01递归的实现、特性以及思维要点  
[递归代码模板](https://shimo.im/docs/DjqqGCT3xqDYwPyY/read)  

实战题目
    • https://leetcode-cn.com/problems/climbing-stairs/
* [括号生成](https://leetcode-cn.com/problems/generate-parentheses/)  
* [翻转二叉树](https://leetcode-cn.com/problems/invert-binary-tree/description/)  
    • https://leetcode-cn.com/problems/validate-binary-search-tree
    • https://leetcode-cn.com/problems/maximum-depth-of-binary-tree
    • https://leetcode-cn.com/problems/minimum-depth-of-binary-tree
    • https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/
每日一课
    • [如何优雅地计算斐波那契数列](https://time.geekbang.org/dailylesson/detail/100028406)
课后作业
    • https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
    • https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
    • https://leetcode-cn.com/problems/combinations/
    • https://leetcode-cn.com/problems/permutations/
    • https://leetcode-cn.com/problems/permutations-ii/


第12课 动态规划
实战题目
    • https://leetcode-cn.com/problems/house-robber/
    • https://leetcode-cn.com/problems/house-robber-ii/description/
* [买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/#/description)  
    • https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
    • https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/
    • https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
    • https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
    • https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
    • https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-l-3/  
    • https://leetcode-cn.com/problems/climbing-stairs/description/
    • https://leetcode-cn.com/problems/triangle/description/
    • https://leetcode.com/problems/triangle/discuss/38735/Python-easy-to-understand-solutions-(top-down-bottom-up)
    • https://leetcode-cn.com/problems/maximum-subarray/
    • https://leetcode-cn.com/problems/maximum-product-subarray/description/
    • https://leetcode-cn.com/problems/coin-change/description/
高级 DP 实战题目
    • https://leetcode-cn.com/problems/perfect-squares/
    • https://leetcode-cn.com/problems/edit-distance/ （重点）
    • https://leetcode-cn.com/problems/jump-game/
    • https://leetcode-cn.com/problems/jump-game-ii/
    • https://leetcode-cn.com/problems/unique-paths/
    • https://leetcode-cn.com/problems/unique-paths-ii/
    • https://leetcode-cn.com/problems/unique-paths-iii/
    • https://leetcode-cn.com/problems/coin-change/
    • https://leetcode-cn.com/problems/coin-change-2/
注意：请大家先消化前面的实战题目，高级 DP 的方法和题解会在课程后面解锁。
课后作业
    • https://leetcode-cn.com/problems/longest-valid-parentheses/
    • https://leetcode-cn.com/problems/minimum-path-sum/
    • https://leetcode-cn.com/problems/edit-distance/
    • https://leetcode-cn.com/problems/decode-ways
    • https://leetcode-cn.com/problems/maximal-square/
    • https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/
    • https://leetcode-cn.com/problems/frog-jump/
    • https://leetcode-cn.com/problems/split-array-largest-sum
    • https://leetcode-cn.com/problems/student-attendance-record-ii/
    • https://leetcode-cn.com/problems/task-scheduler/
    • https://leetcode-cn.com/problems/palindromic-substrings/
    • https://leetcode-cn.com/problems/minimum-window-substring/
    • https://leetcode-cn.com/problems/burst-balloons/


```
#include <ctype.h>

       int isalnum(int c);
       int isalpha(int c);
       int isascii(int c);
       int isblank(int c);
       int iscntrl(int c);
       int isdigit(int c);
       int isgraph(int c);
       int islower(int c);
       int isprint(int c);
       int ispunct(int c);
       int isspace(int c);
       int isupper(int c);
       int isxdigit(int c);
```

```
#include <ctype.h>

       int toupper(int c);
       int tolower(int c);
```

## C++ 常用算法
[C++ 常用算法](http://c.biancheng.net/stl/algorithms/)  
[C++：std::greater()、std::less()、自定义比较函数的规则](https://blog.csdn.net/sandalphon4869/article/details/105419706)  
[C++11 lambda表达式](http://c.biancheng.net/view/3741.html)  


## 动态规划
[漫画：什么是动态规划？](https://zhuanlan.zhihu.com/p/31628866)  
