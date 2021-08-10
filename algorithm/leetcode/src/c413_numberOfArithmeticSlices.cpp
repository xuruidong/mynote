#include "c413_numberOfArithmeticSlices.h"

c413_numberOfArithmeticSlices::c413_numberOfArithmeticSlices()
{
    //ctor
}

c413_numberOfArithmeticSlices::~c413_numberOfArithmeticSlices()
{
    //dtor
}

int numberOfArithmeticSlices(vector<int>& nums) {
    if(nums.size() < 3) {
        return 0;
    }
    int left = 1, right = 2;
    int delta = nums[1] - nums[0];
    int ans = 0, c=2;
    for(;right < nums.size(); ++right, ++left) {
        int d = nums[right] - nums[left];
        if(d == delta) {
            ++c;
            ans += (c-2);
        } else {
            delta = d;
            c = 2;
        }
    }

    return ans;
}
