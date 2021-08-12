
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
[589. N 叉树的前序遍历](https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/)  
    • https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/


第07课丨01递归的实现、特性以及思维要点  
[递归代码模板](https://shimo.im/docs/DjqqGCT3xqDYwPyY/read)  

实战题目
    • https://leetcode-cn.com/problems/climbing-stairs/
* [括号生成](https://leetcode-cn.com/problems/generate-parentheses/)  
* [翻转二叉树](https://leetcode-cn.com/problems/invert-binary-tree/description/)  
    • https://leetcode-cn.com/problems/validate-binary-search-tree
* [104. 二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree)  
    • https://leetcode-cn.com/problems/minimum-depth-of-binary-tree
    • https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/
每日一课
    • [如何优雅地计算斐波那契数列](https://time.geekbang.org/dailylesson/detail/100028406)
课后作业
    • https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
    • https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
    • https://leetcode-cn.com/problems/combinations/
    • https://leetcode-cn.com/problems/permutations/
* [47](https://leetcode-cn.com/problems/permutations-ii/)  


第8课  
[分治代码模板](https://shimo.im/docs/3xvghYh3JJPKwdvt/read)  
[括号生成问题]  
预习题目
https://leetcode-cn.com/problems/powx-n/
https://leetcode-cn.com/problems/subsets/
参考链接  
[牛顿迭代法原理](http://www.matrix67.com/blog/archives/361)  
[牛顿迭代法代码](http://www.voidcn.com/article/p-eudisdmk-zm.html)  


实战题目
https://leetcode-cn.com/problems/majority-element/description/ （简单、但是高频）
https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
https://leetcode-cn.com/problems/n-queens/


第9课  
[DFS 代码模板（递归写法、非递归写法）](https://shimo.im/docs/ddgwCccJQKxkrcTq)  
[BFS 代码模板](https://shimo.im/docs/P8TqKHGKt3ytkYYd/read)  

实战题目
https://leetcode-cn.com/problems/binary-tree-level-order-traversal/#/description
https://leetcode-cn.com/problems/minimum-genetic-mutation/#/description
https://leetcode-cn.com/problems/generate-parentheses/#/description
https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/#/description
课后作业
https://leetcode-cn.com/problems/word-ladder/description/
https://leetcode-cn.com/problems/word-ladder-ii/description/
https://leetcode-cn.com/problems/number-of-islands/
https://leetcode-cn.com/problems/minesweeper/description/


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
[c++ emplace]()  
[c++ 移动构造函数]()  



## 动态规划
[漫画：什么是动态规划？](https://zhuanlan.zhihu.com/p/31628866)  

[从暴力递归到动态规划](https://zhuanlan.zhihu.com/p/75285771)  


#### 典型的二维动态规划问题
[最大公共子序列]()  
[1035. 不相交的线](https://leetcode-cn.com/problems/uncrossed-lines/)  

## 二维前缀和
https://leetcode-cn.com/problems/range-sum-query-2d-immutable/    
https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/  


## DFS  BFS
https://leetcode-cn.com/problems/range-sum-of-bst  


## 回溯
对于寻找所有可行解的题，我们都可以尝试用「搜索回溯」的方法来解决。
[39. 组合总和](https://leetcode-cn.com/problems/combination-sum/)  
https://leetcode-cn.com/problems/combination-sum/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-2/

[46. 全排列](https://leetcode-cn.com/problems/permutations/)  

## 位运算
异或的性质  
[](https://leetcode-cn.com/problems/xor-operation-in-an-array/solution/shu-zu-yi-huo-cao-zuo-by-leetcode-solution/)  


## 树状数组
[]()  


[1818. 绝对差值和](https://leetcode-cn.com/problems/minimum-absolute-sum-difference/)  
找到 数组中最解决 n 的值  
学到了两个很灵性的操作：

* 「找到 nums1 中最接近 nums2[i] 的值」
  这个值可能在二分查找过程中的 mid-1/mid/mid+1 中出现，为了不侵入二分查找，可以转化为「找到 nums1 中大于等于 nums2[i] 的最小下标 j」，那么该值可能在 j（j < n） 或 j-1（j > 0）
* 遍历过程中使用了取模操作，可能会导致最终 sum < maxn，因此结果要使用 (sum - maxn + mod) % mod 的形式



## 计数排序
[1846. 减小和重新排列数组后的最大元素](https://leetcode-cn.com/problems/maximum-element-after-decreasing-and-rearranging/)  
【纯C】O(n)一次AC，又是一天没依靠题解独立完成了最优解，现在看到这种最大值不超过数组大小的立马就会想到计数，虽然和题解写的有些出入，但还是O(N)的时间复杂度。

首先申请一个arrSize+1空间大小的hash用来计数
ret是返回值，我们假设arr是理想情况，由1开始每次递增1，所以ret初始为arrSize
less是等下用来记录剩余元素数量的，初始大小为arrSize
然后就是计数了，大于arrSize的数量全部算到hash[arrSize]的头上，其余的记在hash[arr[i]]上
计数完毕后，i从1循环到arrSize
用less每次减去已经计数的元素数量来记录剩余元素的数量
剩余元素我们假设是按照每次递增1的顺序排列
如果当前的i加上剩余元素小于ret，ret则等于i+less，否则ret不变。
为什么？因为题目规定只能排序或者减小元素大小，且元素间差的绝对值必须小于等于1，剩余元素我们假设是按照每次递增1的顺序排列的，所以最终结果是不可能超过i+less的。



## 拓扑排序
[802. 找到最终的安全状态](https://leetcode-cn.com/problems/find-eventual-safe-states/)  


## 滑动窗口
[1838. 最高频元素的频数](https://leetcode-cn.com/problems/frequency-of-the-most-frequent-element/)  



## 单源最短路径算法 \texttt{Dijkstra}Dijkstra
单源最短路径算法 \texttt{Dijkstra}Dijkstra
$ddd$
[743. 网络延迟时间](https://leetcode-cn.com/problems/network-delay-time/)  




node->prev->next = node->next;
node->next->prev = node->prev;
node->prev = NULL;
node->next = NULL;

if(head == node) {
    head = node->next;
    node->next->prev = NULL;
}

if(tail == node) {
    tail = node->prev;
    node->prev->next = NULL;
}