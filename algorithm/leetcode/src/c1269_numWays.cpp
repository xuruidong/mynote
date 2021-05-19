#include "c1269_numWays.h"

c1269_numWays::c1269_numWays()
{
    //ctor
}

c1269_numWays::~c1269_numWays()
{
    //dtor
}

static void recur(int sum, int step, int steps, int arrLen, int &ans)
{
    if(step > steps) {
        if(sum == 0) {
            ++ans;
        }
        return;
    }
    if(sum < (arrLen-1) && sum <= (steps>>1)) {
        recur(sum+1, step+1, steps, arrLen, ans);
    }
    if(sum >0) {
        recur(sum-1, step+1, steps, arrLen, ans);
    }
    recur(sum, step+1, steps, arrLen, ans);
}

int numWays(int steps, int arrLen)
{
    int ans = 0;
    recur(0, 1, steps, arrLen, ans);
    return ans;
}

int numWays2(int steps, int arrLen)
{/*
    int len = min(steps/2+1, arrLen);
    long dp[2][len+2] = {{0}};

    dp[0][1] = 1;
    for(int i=1; i<= steps; ++i) {
        for(int j=1; j<=len; ++j) {
            dp[i&1][j] = (dp[(i-1)&1][j-1] + dp[(i-1)&1][j] + dp[(i-1)&1][j+1])%1000000007;
        }
    }

    return dp[steps&1][1];*/
}
