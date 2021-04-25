#include "c213_rob.h"

c213_rob::c213_rob()
{
    //ctor
}

c213_rob::~c213_rob()
{
    //dtor
}

static int rob_dp(vector<int> &nums, int start, int e)
{
    int len = e-start+1;
    if(len < 1){
        return 0;
    }
    if(len == 1){
        return nums[start];
    }
    if(len == 2){
        return max(nums[start], nums[e]);
    }
    int n1 = nums[start];
    int n2 = max(nums[start], nums[start+1]);

    int val = 0;
    for(int i=start+2; i<len; ++i){
        val = max(n1+nums[i], n2);
        n1 = n2;
        n2 = val;
    }

    return val;
}

int c213_rob::rob(vector<int>& nums) {
    int len =  nums.size();
    if(len < 1){
        return 0;
    }
    if(len == 1){
        return nums[0];
    }
    if(len == 2){
        return max(nums[0], nums[1]);
    }
    /*
    if(len == 3){
        return max(nums[0], max(nums[1], nums[2]));
    }
    */

    return max(rob_dp(nums, 0, len-2), rob_dp(nums, 1, len-1));
}
