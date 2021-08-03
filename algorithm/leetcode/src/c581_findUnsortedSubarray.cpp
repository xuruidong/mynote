#include "c581_findUnsortedSubarray.h"

c581_findUnsortedSubarray::c581_findUnsortedSubarray()
{
    //ctor
}

c581_findUnsortedSubarray::~c581_findUnsortedSubarray()
{
    //dtor
}

int findUnsortedSubarray(vector<int> &nums)
{
    vector<int> tmp(nums);
    sort(tmp.begin(), tmp.end());
    int start = 0;
    while(start < tmp.size() && nums[start] == tmp[start]) {
        ++start;
    }
    int r = tmp.size()-1;
    while(r>start && nums[r] == tmp[r]) {
        --r;
    }
    return r-start;
}
