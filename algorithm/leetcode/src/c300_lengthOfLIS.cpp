#include "c300_lengthOfLIS.h"

c300_lengthOfLIS::c300_lengthOfLIS()
{
    //ctor
}

c300_lengthOfLIS::~c300_lengthOfLIS()
{
    //dtor
}

int lengthOfLIS(vector<int>& nums)
{
    int len = nums.size();
    int ans = 1;
    vector<vector<int>> dp;

    int sum = 1;
    vector<int> tmp(len);
    tmp[0] = 1;
    for(int i=1; i<len; ++i) {
        if(nums[i] > nums[i-1]) {
            tmp[i] = ++sum;
            ans = ans>sum?ans:sum;
        } else {
            sum = 1;
            tmp[i] = 1;
        }
    }
    dp.push_back(tmp);
    for(int i=1; i<len; ++i) {
        sum = 0;
        int pre = nums[i-1];
        for(int j=0; j<len; ++j) {
            if(j<i) {
                tmp[j] = 0;
                //pre = nums[j];
            } else if(i==j) {
                tmp[j] = 1;
                sum = 1;
                pre = nums[j];
            } else {
                if(nums[j] > pre) {
                    ++sum;
                } else {
                    sum = 1;
                }
                if(sum > dp[i-1][j-1]) {
                    tmp[j] = sum;
                    pre = nums[j];
                } else {
                    tmp[j] = dp[i-1][j-1];
                    pre = nums[j-1];
                }
                tmp[j] = sum > dp[i-1][j-1]?sum:dp[i-1][j-1];
                ans = ans>tmp[j]?ans:tmp[j];
            }
        }
        dp.push_back(tmp);
    }
    return ans;
}
