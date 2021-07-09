#include "m17_10_majorityElement.h"

m17_10_majorityElement::m17_10_majorityElement()
{
    //ctor
}

m17_10_majorityElement::~m17_10_majorityElement()
{
    //dtor
}

int majorityElement(vector<int>& nums)
{
    if(nums.size() == 0) {
        return -1;
    }
    if(nums.size() == 1) {
        return nums[0];
    }

    unordered_map<int, int> umap;
    for(int n:nums) {
        ++umap[n];
    }
    for(auto &it:umap) {
        if(it->second > (nums.size()>>1)) {
            return it->first;
        }
    }
    return -1;
}
