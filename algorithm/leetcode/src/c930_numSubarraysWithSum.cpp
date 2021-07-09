#include "c930_numSubarraysWithSum.h"

c930_numSubarraysWithSum::c930_numSubarraysWithSum()
{
    //ctor
}

c930_numSubarraysWithSum::~c930_numSubarraysWithSum()
{
    //dtor
}

int numSubarraysWithSum(vector<int>& nums, int goal)
{
    /* wrong answer
    int sum = 0;
    int ans = 0;
    unordered_map<int, int> umap;
    for(int i=0; i<nums.size(); ++i) {
        sum += nums[i];
        ++umap[sum];
        //nums[i] = sum;
        ans += umap[sum-goal];
    }

    return ans;
    */
    int sum = 0;
    int ans = 0;
    unordered_map<int, int> umap;
    for(int i=0; i<nums.size(); ++i) {
        ++umap[sum];
        sum += nums[i];
        //nums[i] = sum;
        ans += umap[sum-goal];
    }

    return ans;
}
