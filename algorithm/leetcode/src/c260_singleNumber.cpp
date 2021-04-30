#include "c260_singleNumber.h"

c260_singleNumber::c260_singleNumber()
{
    //ctor
}

c260_singleNumber::~c260_singleNumber()
{
    //dtor
}

vector<int> c260_singleNumber::singleNumber(vector<int>& nums) {
    int len = nums.size();
    int tmp = 0;
    for(int i=0; i<len; ++i) {
        tmp ^= nums[i];
    }
    //tmp = tmp^(-tmp);
    //tmp = tmp<0?-tmp:tmp;
    int div = 1;
    while ((div & tmp) == 0)
        div <<= 1;
    int a=0, b=0;
    for(int i=0; i<len; ++i) {
        if(nums[i] & div) {
            a ^= nums[i];
        } else {
            b ^= nums[i];
        }
    }
    return {a, b};
}
