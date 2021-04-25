#include "c198_rob.h"
#include "common.h"

c198_rob::c198_rob()
{
    //ctor
}

c198_rob::~c198_rob()
{
    //dtor
}

int c198_rob::rob(vector<int>& nums) {
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

    int n1 = nums[0];
    int n2 = max(nums[0], nums[1]);

    int val = 0;
    for(int i=2; i<len; ++i){
        val = max(n1+nums[i], n2);
        n1 = n2;
        n2 = val;
    }

    return val;
}
