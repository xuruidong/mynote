#include "c137_singleNumber.h"

c137_singleNumber::c137_singleNumber()
{
    //ctor
}

c137_singleNumber::~c137_singleNumber()
{
    //dtor
}


int c137_singleNumber::singleNumber(vector<int>& nums) {
    int len = nums.size();
    int ans = nums[0];
    for(int i=1; i<len; ++i) {
       // ans = ~(ans ^ nums[i]);
    }
    return ~ans;
}
