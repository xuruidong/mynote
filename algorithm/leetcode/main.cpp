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
#include "c403_canCross.h"
#include "c45_jump.h"
#include "c260_singleNumber.h"

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

ÊäÈë£ºnums = [3,9,6], k = 2
Êä³ö£º1
*/

int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int ans = 1;
    int left = 0;
    int sum = 0;
    for(int i=1; i<nums.size(); ) {
        if(nums[i-1] < nums[i]) {
            int delt = nums[i] - nums[i-1];

            if(sum + (i-left+1)*delt > k) {
                //ans = ans>(i-left+1)?ans:(i-left+1);
                ans = ans>(i-left)?ans:(i-left);
                sum -= nums[i-1] - nums[left];
                ++left;
            } else {
                ans = ans>(i-left+1)?ans:(i-left+1);
                sum += (i-left+1)*delt;
                ++i;
            }
        } else {
            ans = ans>(i-left+1)?ans:(i-left+1);
            ++i;
        }
    }

    return ans;
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

    vector<int> nums2 = {1,4,8,13};
    cout<<maxFrequency(nums2, 5)<<endl;

    vector<int> stones = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255,256,257,258,259,260,261,262,263,264,265,266,267,268,269,270,271,272,273,274,275,276,277,278,279,280,281,282,283,284,285,286,287,288,289,290,291,292,293,294,295,296,297,298,299,300,301,302,303,304,305,306,307,308,309,310,311,312,313,314,315,316,317,318,319,320,321,322,323,324,325,326,327,328,329,330,331,332,333,334,335,336,337,338,339,340,341,342,343,344,345,346,347,348,349,350,351,352,353,354,355,356,357,358,359,360,361,362,363,364,365,366,367,368,369,370,371,372,373,374,375,376,377,378,379,380,381,382,383,384,385,386,387,388,389,390,391,392,393,394,395,396,397,398,399,400,401,402,403,404,405,406,407,408,409,410,411,412,413,414,415,416,417,418,419,420,421,422,423,424,425,426,427,428,429,430,431,432,433,434,435,436,437,438,439,440,441,442,443,444,445,446,447,448,449,450,451,452,453,454,455,456,457,458,459,460,461,462,463,464,465,466,467,468,469,470,471,472,473,474,475,476,477,478,479,480,481,482,483,484,485,486,487,488,489,490,491,492,493,494,495,496,497,498,499,500,501,502,503,504,505,506,507,508,509,510,511,512,513,514,515,516,517,518,519,520,521,522,523,524,525,526,527,528,529,530,531,532,533,534,535,536,537,538,539,540,541,542,543,544,545,546,547,548,549,550,551,552,553,554,555,556,557,558,559,560,561,562,563,564,565,566,567,568,569,570,571,572,573,574,575,576,577,578,579,580,581,582,583,584,585,586,587,588,589,590,591,592,593,594,595,596,597,598,599,600,601,602,603,604,605,606,607,608,609,610,611,612,613,614,615,616,617,618,619,620,621,622,623,624,625,626,627,628,629,630,631,632,633,634,635,636,637,638,639,640,641,642,643,644,645,646,647,648,649,650,651,652,653,654,655,656,657,658,659,660,661,662,663,664,665,666,667,668,669,670,671,672,673,674,675,676,677,678,679,680,681,682,683,684,685,686,687,688,689,690,691,692,693,694,695,696,697,698,699,700,701,702,703,704,705,706,707,708,709,710,711,712,713,714,715,716,717,718,719,720,721,722,723,724,725,726,727,728,729,730,731,732,733,734,735,736,737,738,739,740,741,742,743,744,745,746,747,748,749,750,751,752,753,754,755,756,757,758,759,760,761,762,763,764,765,766,767,768,769,770,771,772,773,774,775,776,777,778,779,780,781,782,783,784,785,786,787,788,789,790,791,792,793,794,795,796,797,798,799,800,801,802,803,804,805,806,807,808,809,810,811,812,813,814,815,816,817,818,819,820,821,822,823,824,825,826,827,828,829,830,831,832,833,834,835,836,837,838,839,840,841,842,843,844,845,846,847,848,849,850,851,852,853,854,855,856,857,858,859,860,861,862,863,864,865,866,867,868,869,870,871,872,873,874,875,876,877,878,879,880,881,882,883,884,885,886,887,888,889,890,891,892,893,894,895,896,897,898,899,900,901,902,903,904,905,906,907,908,909,910,911,912,913,914,915,916,917,918,919,920,921,922,923,924,925,926,927,928,929,930,931,932,933,934,935,936,937,938,939,940,941,942,943,944,945,946,947,948,949,950,951,952,953,954,955,956,957,958,959,960,961,962,963,964,965,966,967,968,969,970,971,972,973,974,975,976,977,978,979,980,981,982,983,984,985,986,987,988,989,990,991,992,993,994,995,996,997,998,999};
    cout<<"sizeof stones="<<stones.size()<<endl;
    c403_canCross c403;
    cout<<c403.canCross(stones)<<endl;

    c45_jump c45;
    vector<int> jumpv = {2,1,2,3,4,1};


    c260_singleNumber c260;
    vector<int> ret260 = c260.singleNumber(jumpv);
    u.vector_print(ret260);
   // maptest();
    return 0;
}
