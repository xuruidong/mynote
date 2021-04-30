#include "c45_jump.h"

c45_jump::c45_jump()
{
    //ctor
}

c45_jump::~c45_jump()
{
    //dtor
}

int c45_jump::jump(vector<int>& nums)
{
    int len = nums.size();
    vector<int> dp(len, INT_MAX);
    dp[0] = 0;
    cout<<"=========="<<endl;
    for(int i=0; i<len; ++i) {
        cout<<"===@"<<i<<endl;
        for(int j=1; j<=nums[i] && i+j < len; ++j) {
            dp[i+j] = dp[i+j]<(dp[i] + 1)?dp[i+j]:(dp[i] + 1);
            cout<<"==="<<i+j<<"~~"<<dp[j]<<endl;
        }
        cout<<dp[i]<<endl;
    }
    return dp[len-1];
}
