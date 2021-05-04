#include "c47_permuteUnique.h"

c47_permuteUnique::c47_permuteUnique()
{
    //ctor
}

c47_permuteUnique::~c47_permuteUnique()
{
    //dtor
}

static void recur(vector<int> &nums, vector<int> &prev, vector<vector<int>> &ans)
{
    if(prev.size() == nums.size()) {
        ans.push_back(prev);
        return ;
    }

    vector<int> used(22, 0);
    used[21] = 1;
    for(int i=0; i<nums.size(); ++i) {
        if(used[nums[i] + 10] == 0) {
            int tmp = nums[i];
            prev.push_back(nums[i]);
            used[nums[i] + 10] = 1;
            nums[i] = 11;
            recur(nums, prev, ans);
            prev.pop_back();
            nums[i] = tmp;
        }
    }
}

vector<vector<int>> c47_permuteUnique::permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> prev;
    vector<int> used(22, 0);
    used[21] = 1;

    recur(nums, prev, ans);
    return ans;
}

void c47_permuteUnique::test()
{
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> ret = permuteUnique(nums);
    for(auto &it : ret) {
        utils::vector_print(it);
    }
    cout<<"c47 test end"<<endl;
}
