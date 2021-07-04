#include "c654_findErrorNums.h"

c654_findErrorNums::c654_findErrorNums()
{
    //ctor
}

c654_findErrorNums::~c654_findErrorNums()
{
    //dtor
}

vector<int> findErrorNums(vector<int> &nums)
{
    unordered_set<int> uset;
    vector<int> ans;
    int sum = 0;

    for(int i=0; i<nums.size(); ++i) {
        sum += nums[i];
        if (uset.find(nums[i]) != uset.end()) {
            ans.push_back(nums[i]);
        } else {
            uset.insert(nums[i]);
        }
    }

    int sum2 = ((1+nums.size())*nums.size())>>1;
    ans.push_back(sum2 - (sum-ans[0]));
    return ans;
}
