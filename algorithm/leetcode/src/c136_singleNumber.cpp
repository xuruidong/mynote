#include "c136_singleNumber.h"

c136_singleNumber::c136_singleNumber()
{
    //ctor
}

c136_singleNumber::~c136_singleNumber()
{
    //dtor
}

int c136_singleNumber::singleNumber(vector<int>& nums)
{
    int ans = 0;
    for(int n:nums) {
        ans ^= n;
    }
    return ans;
}
