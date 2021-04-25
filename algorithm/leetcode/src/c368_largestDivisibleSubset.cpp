#include "c368_largestDivisibleSubset.h"

c368_largestDivisibleSubset::c368_largestDivisibleSubset()
{
    //ctor
}

c368_largestDivisibleSubset::~c368_largestDivisibleSubset()
{
    //dtor
}

vector<int> c368_largestDivisibleSubset::largestDivisibleSubset(vector<int>& nums)
{
    if(nums.size() < 2) {
        return nums;
    }
    std::sort(nums.begin(), nums.end());

    vector<int> ans;
#if 0
    int largest_num = nums[nums.size()-1];
    for(int i=0; i<nums.size()-1; ++i) {
        int pre = nums[i];
        //cout<<"===pre "<<pre<<endl;
        vector<int> tmp;
        tmp.push_back(nums[i]);
        for(int j=i+1; j<nums.size(); ++j) {

            if(nums[j] % pre == 0) {
                tmp.push_back(nums[j]);
                pre = nums[j];
                //cout<<"   ===pre "<<pre<<endl;
            }
        }
        if(tmp.size() > ans.size()) {
            ans.assign(tmp.begin(), tmp.end());
        }
    }
#endif
    return ans;
}
