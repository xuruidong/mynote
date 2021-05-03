#include "c46_permute.h"

c46_permute::c46_permute()
{
    //ctor
}

c46_permute::~c46_permute()
{
    //dtor
}

static void recur(vector<int>& nums, vector<int>& prev, vector<vector<int>> &ans)
{
    if(nums.size() == 0) {
        ans.push_back(prev);
        return;
    }

    for(int i=0; i<nums.size(); ++i) {
        prev.push_back(nums[i]);
        vector<int> tmp(nums);
        tmp.erase(tmp.begin()+i);
        recur(tmp, prev, ans);
        prev.pop_back();
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> prev;
    recur(nums, prev, ans);
    return ans;
}
