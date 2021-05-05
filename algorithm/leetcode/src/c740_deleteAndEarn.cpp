#include "c740_deleteAndEarn.h"

c740_deleteAndEarn::c740_deleteAndEarn()
{
    //ctor
}

c740_deleteAndEarn::~c740_deleteAndEarn()
{
    //dtor
}

static void dfs(vector<int> &nums, unordered_set<int> &deleted_set, int last_ans, int &ans)
{
    // XXXXXXXXX
#if 0
    if(nums.size() == 0) {
        ans = ans>last_ans?ans:last_ans;
        return;
    }
    int used = 0;
    for(int i=0; i<nums.size(); ++i) {
        if(nums[i] != 0 && nums[i] != used && deleted_set.find(nums[i]) == deleted_set.end()) {
            used = nums[i];
            last_ans += nums[i];
            //nums[i] = 0;
            deleted_set.insert(used+1);
            deleted_set.insert(used-1);
            vector<int> tmp(nums);
            tmp.remove(tmp.begin()+i);
            dfs(tmp, deleted_set, ans);

            deleted_set.erase(used+1);
            deleted_set.erase(used-1);
        }
    }
#endif
}

int c740_deleteAndEarn::deleteAndEarn(vector<int>& nums)
{
    if(nums.size() < 1) {
        return 0;
    }
    if(nums.size() == 1) {
        return nums[0];
    }

    int max_num = 0;
    for(int i=0; i<nums.size(); ++i) {
        max_num = max(max_num, nums[i]);
    }
    vector<int> tmp(max_num+1, 0);
    for(int i=0; i<nums.size(); ++i) {
        ++tmp[nums[i]];
    }
    /*
    if(max_num <= 1) {
        return max_num*tmp[max_num];
    }
    */
    vector<int> dp(max_num+1);
    dp[1] = tmp[1];
    for(int i=2; i<dp.size(); ++i) {
        dp[i] = max(dp[i-1], dp[i-2]+i*tmp[i]);
    }

    return dp[max_num];
}

void c740_deleteAndEarn::test()
{
    vector<int> nums = {3,1};
    cout<<endl;
    cout<<"c740 test start..."<<endl;
    cout<<deleteAndEarn(nums)<<endl;
    cout<<"c740 test end"<<endl;
}
