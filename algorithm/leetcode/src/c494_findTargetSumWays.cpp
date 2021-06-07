#include "c494_findTargetSumWays.h"

c494_findTargetSumWays::c494_findTargetSumWays()
{
    //ctor
}

c494_findTargetSumWays::~c494_findTargetSumWays()
{
    //dtor
}

static void process(vector<int> &nums, int index, int sum, int target, int &ans)
{
    if(index >= nums.size()) {
        if(sum == target) {
            ++ans;
        }
        return ;
    }

    process(nums, index+1, sum-nums[index], target, ans);
    process(nums, index+1, sum+nums[index], target, ans);
}

int findTargetSumWays(vector<int>& nums, int target) {
    int ans = 0;
    process(nums, 0, 0, target, ans);
    return ans;
}
