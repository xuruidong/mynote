#include <iostream>
#include <string>
#include <cstring>
#include <vector>
//#include <string.h>
#include<algorithm>
#include <unordered_set>
#include "Solution.h"
#include "c208_Trie.h"
#include "utils.h"
#include "c368_largestDivisibleSubset.h"

using namespace std;

int strStr(string haystack, string needle)
{
    if (needle == ""){
        //cout << "s2 is null" << endl;
        return 0;
    }
    else if(needle.size() > haystack.size()){
        return -1;
    }
    std::basic_string<char>::size_type i = 0, j = 0;
    int i_tmp = 0;
    for (i=0; i < haystack.size() - needle.size() + 1; i++){
        i_tmp = i;
        for (j=0; j<needle.size(); j++){
            if (haystack[i_tmp] == needle[j]){
                i_tmp ++;
            }
            else{
                break;
            }
        }
        if (j==needle.size()){
            return i;
        }

    }
    return -1;
}

void swap(int& a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void moveZeroes(vector<int>& nums)
{
    std::vector<int>::size_type j = 0;
    /*
    for(std::vector<int>::size_type i = 0; i<nums.size(); i++){
        if (nums[i] != 0){
            swap(nums[j++], nums[i]);
        }
    }
    */
    std::vector<int>::size_type i = 0;
    for(auto n: nums){
        if (n != 0){
            printf("%p=====%p\n", &n, &nums[i]);
            cout << nums[j] << "---"<< n << "---"<< nums[i] << endl;
            swap(nums[j++], nums[i]);
            cout << nums[j-1] << "   "<< n << "---"<< nums[i] << endl;
        }
        i++;
    }

}

int maxArea(vector<int>& height)
{
    vector<int>::size_type i = 0, j = height.size() - 1;
    int area = 0, area_tmp = 0;
    for (; i < j;){
        area_tmp = (j - i) * (height[j] > height[i]? height[i]: height[j]);
        if (area_tmp > area){
            area = area_tmp;
        }
        if(height[i] < height[j]){
            i++;
        }
        else{
            --j;
        }
    }
    return area;
}

vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> ret;
    std::vector<int>::size_type i=0, j=0;
    for(i=0; i<nums.size(); i++){
        for(j=i+1; j<nums.size(); j++){
            cout<<"+++" << nums[i] + nums[j] <<endl;
            if(nums[i] + nums[j] == target){
                cout<<"~~~"<<i <<"---" << j<< endl;
                ret.push_back(i);
                ret.push_back(j);
                return ret;
            }
        }
    }
    return ret;
}

#include <unordered_map>

vector<int> twoSum2(vector<int>& nums, int target)
{
    vector<int> ret;
    unordered_map<int, int> map_tmp;
    std::vector<int>::size_type i=0;
    for(; i<nums.size(); i++){
        auto it = map_tmp.find(target-nums[i]);
        if( it == map_tmp.end() ){
            map_tmp.insert(pair<int, int>(nums[i], i));
        }
        else{
            ret.push_back(i);
            ret.push_back(it->second);
            return ret;
        }
    }
    return ret;
}

/*
vector<int> twoSum3(vector<int>& nums, int target)
{
    vector<int> ret;

    std::vector<int>::size_type i=0, j=nums.size()-1;

    std::sort(nums);
    if(nums[i] > target){
        return {};
    }
    if (nums[])
    for(; i<j; ++i){
        for(; i<j; --j){
            if(nums[i] + nums[j] == target){
                return {i, j};
            }
            else if(nums[i])
        }
        auto it = map_tmp.find(target-nums[i]);
        if( it == map_tmp.end() ){
            map_tmp.insert(pair<int, int>(nums[i], i));
        }
        else{
            ret.push_back(i);
            ret.push_back(it->second);
            return ret;
        }
    }
    return {};
}
*/

int climbStairs(int n)
{
    static std::unordered_map<int, int> result;
    if(n == 1){
        return 1;
    }
    if (n == 2){
        return 2;
    }
    int r1 = 0, r2 = 0;
    auto it = result.find(n-1);
    if(it == result.end()){
        r1 = climbStairs(n-1);
        result[n-1] = r1;
    }
    else{
        r1 = it->second;
    }

    auto it2 = result.find(n-2);
    if (it2 == result.end()){
        result[n-2] = climbStairs(n-2);
    }
    else{
        return r1 + it2->second;
    }


    return r1 + result[n-2];
}

int climbStairs2(int n)
{
    int i;
    int s1 = 1;
    int s2 = 2;

    for(i=3; i<=n; ++i){
            //cout << "===111#"<<i <<endl;
        if(i%2){
            s1 = s1+s2;
        }
        else{
            s2 = s1+s2;
        }
    }
    if(n%2){
        return s1;
    }
    return s2;
}

// sum of 3 nums
std::vector<std::vector<int>> threesum(std::vector<int> &nums)
{
    std::vector<std::vector<int>> result = {};
    std::vector<int>::size_type i=0, j=0, k=0;
    //std::unordered_map<int, int> umap;
    //int tmp = 0;

    if (nums.size() < 3){
        return result;
    }
    std::sort(nums.begin(), nums.end());
    /*
    for(i=0; i<nums.size(); ++i){
        umap[nums[i]]=i;
        std::cout<<nums[i]<<"  ";
    }
    std::cout<<std::endl;
*/
    j=nums.size()-1;
    for(i=0; i<nums.size()-1; ++i){
        if(i>0 && nums[i] == nums[i-1]){
            continue;
        }

        for(j=nums.size()-1;j>i+1;--j){
            if(j<nums.size()-1 && nums[j] == nums[j+1]){
                continue;
            }

            if(nums[i]*2+nums[j]>0){
                break;
            }
            if(nums[j]*2+nums[i]<0){
                break;
            }

            for(k=i+1; k<j;++k){
                if(k>i+1 && nums[k] == nums[k-1]){
                    continue;
                }
                if(nums[i] + nums[k]+nums[j]>0){
                    break;
                }
                else if(nums[i] + nums[k]+nums[j]==0){
                    result.push_back({nums[i], nums[k], nums[j]});
                }
            }
        }
    }
    return result;
}


std::vector<std::vector<int>> threesum2(std::vector<int> &nums)
{
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());
    int ai, bi, ci;
    if(nums.size() < 3){
        return result;
    }
    for(ai=0; ai<nums.size()-2; ++ai){
        if(ai >0 && nums[ai] == nums[ai-1]){
            continue;
        }
        if(nums[ai] > 0){
            break;
        }
        ci=nums.size()-1;
        for(bi=ai+1; bi<nums.size()-1; ++bi){
            if(bi > ai+1 && nums[bi] == nums[bi-1]){
                continue;
            }

            if(nums[ai]+nums[bi] > 0){
                break;
            }

            /*if (nums[ai]+nums[bi]+nums[ci]<0){
                continue;
            }*/
            for(; ci>bi; --ci){
                if(ci < nums.size()-1 && nums[ci] == nums[ci+1]){
                    continue;
                }
                if(nums[ai]+nums[bi]+nums[ci]>0){
                    continue;
                }
            }
            if (ci == bi){
                break;
            }
            if(nums[ai]+nums[bi]+nums[ci] == 0){
                result.push_back({nums[ai], nums[bi], nums[ci]});
                break;
            }
        }
    }
    return result;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 struct ListNode {
      int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        struct ListNode *last = NULL;
        struct ListNode *current = NULL;
        struct ListNode *nxt = NULL;
        for(struct ListNode *it = head; it != NULL; it = nxt){
            current = it;
            nxt = current->next;
            current->val = it->val;
            current->next = last;
            last = current;
        }
        return last;
    }

    ListNode* reverseList2(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        struct ListNode *n = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return n;
    }

    ListNode* swapPairs(ListNode* head)
    {
        if(head == NULL || head->next == NULL){
            return head;
        }
        struct ListNode *tmp = NULL;
        struct ListNode *prev = NULL;
        struct ListNode *newHead = head->next;
        for(struct ListNode *it = head; it != NULL; it = it->next){
            if(it->next){
                tmp = it->next;
                it->next = it->next->next;
                tmp->next = it;
            }
            else{
                break;
            }

            if(prev){
                prev->next = tmp;
            }
            else{
                prev = it;
            }

        }

        return newHead;
    }


};

#define COUNT   10000
int maptest()
{
    clock_t start, finish;
    int c=0;
    std::unordered_map<int, int> maptmp;
    for(int i=0; i< 10000; ++i){
        maptmp[i] = 1000+i;
    }

    //std::unordered_map<int, int>::const_iterator it2;
    auto it2 = maptmp.begin();
    start = clock();
    for(c = 0; c<COUNT; ++c){
        for(it2 = maptmp.begin(); it2 != maptmp.end(); ++it2){
            //std::cout<<it->second<<"  ";
        }
    }
    finish = clock();
    std::cout<<finish-start<<std::endl;

    //std::unordered_map<int, int>::iterator it;
    auto it = maptmp.begin();
    start = clock();
    for(c = 0; c<COUNT; ++c){
        for(it = maptmp.begin(); it != maptmp.end(); ++it){
            //std::cout<<it->second<<"  ";
        }
    }
    finish = clock();
    std::cout<<finish-start<<std::endl;


}

void c208_Trie_test()
{
    c208_Trie t;
    t.insert("apple");
    cout<<t.search("apple")<<endl;
    cout<<t.search("app")<<endl;
    cout<<t.startsWith("app")<<endl;
    t.insert("app");
    cout<<t.search("app")<<endl;
}

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


int sumBase(int n, int k) {
    int sum = 0;

    while(n) {
        sum += n%k;
        n /= k;
    }
    return sum;
}


/*
[9940,9995,9944,9937,9941,9952,9907,9952,9987,9964,9940,9914,9941,9933,9912,9934,9980,9907,9980,9944,9910,9997]
7925

22

[9930,9923,9983,9997,9934,9952,9945,9914,9985,9982,9970,9932,9985,9902,9975,9990,9922,9990,9994,9937,9996,9964,9943,9963,9911,9925,9935,9945,9933,9916,9930,9938,10000,9916,9911,9959,9957,9907,9913,9916,9993,9930,9975,9924,9988,9923,9910,9925,9977,9981,9927,9930,9927,9925,9923,9904,9928,9928,9986,9903,9985,9954,9938,9911,9952,9974,9926,9920,9972,9983,9973,9917,9995,9973,9977,9947,9936,9975,9954,9932,9964,9972,9935,9946,9966]
3056

73
*/

int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int ret = 0;
    int i=0;
    for(i=0; i<nums.size()-1; ++i) {
        if(nums[i] < nums[i+1]) {
            int delt = nums[i+1] - nums[i];
            if((i+1)*delt <= k) {
                for(int j=0; j<=i; ++j) {
                    nums[j] = nums[i+1];
                }
            } else {
                ret = i+1;
                break;
            }
            k -= (i+1)*delt;
            if(k == 0) {
                ret = i+1;
                break;
            }
        }
    }

    utils u;
    u.vector_print(nums);

    int tmp = 1;
    for(int i=0; i<nums.size()-1; ++i) {
        if(nums[i] == nums[i+1]) {
            ++tmp;
        } else {
            cout<<ret<<"---"<<tmp<<endl;
            ret = ret>tmp?ret:tmp;
            tmp = 1;
        }
    }
    return ret>tmp?ret:tmp;
}

int longestBeautifulSubstring(string word) {
    char d[26] = {'a','e','i','o','u'};
    memset(d, 0 ,26);
    d['a' - 'a'] = 'e';
    d['e' - 'a'] = 'i';
    d['i' - 'a'] = 'o';
    d['o' - 'a'] = 'u';
    d['u' - 'a'] = 'u';

    int sum = 0;
    int ans = 0;
    char pre = 0;
    int i=0;
    for(i=0; i<word.size(); ++i) {
        if(word[i] == 'a') {
            pre = 'a';
            break;
        }
    }
    if(pre != 'a') {
        return 0;
    }
    int j=i;
    for(j=i; j<word.size(); ++j) {
        if(pre == 0) {
            if(word[j] == 'a') {
                pre = 'a';
            } else {
                continue;
            }
        }
        if(word[j] == pre ) {
            sum ++;
        } else if(word[j] == d[pre-'a']) {
            sum ++;
            pre = d[pre-'a'];
        } else {
            if(pre == 'u'){
                ans = ans>sum?ans:sum;
            }
            sum =0;
            pre = 0;
        }
    }

    return ans;
}

int main()
{
    utils u;
    cout << "Hello world!" << endl;
    cls_demo c1(1,100);
    cls_demo c2(2, 99);

    //cout<< (c1<c2) <<endl;
    vector<cls_demo> v;
    v.push_back(c1);
    v.push_back(c2);
    sort(v.begin(), v.end(), [](cls_demo &c1, cls_demo &c2)->bool{
            return c1.vb < c2.vb;
         });
    for(auto &e: v){
        //e.print();
    }

    vector<int> nums = {5,9,18,54,108,540,90,180,360,720};
    c368_largestDivisibleSubset c368;
    vector<int> ret = c368.largestDivisibleSubset(nums);
    u.vector_print(ret);

    vector<int> nums2 = {9930,9923,9983,9997,9934,9952,9945,9914,9985,9982,9970,9932,9985,9902,9975,9990,9922,9990,9994,9937,9996,9964,9943,9963,9911,9925,9935,9945,9933,9916,9930,9938,10000,9916,9911,9959,9957,9907,9913,9916,9993,9930,9975,9924,9988,9923,9910,9925,9977,9981,9927,9930,9927,9925,9923,9904,9928,9928,9986,9903,9985,9954,9938,9911,9952,9974,9926,9920,9972,9983,9973,9917,9995,9973,9977,9947,9936,9975,9954,9932,9964,9972,9935,9946,9966};
    cout<<maxFrequency(nums2, 3056)<<endl;
   // maptest();
    return 0;
}
