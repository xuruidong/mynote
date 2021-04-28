#include "c279_numSquares.h"

c279_numSquares::c279_numSquares()
{
    //ctor
}

c279_numSquares::~c279_numSquares()
{
    //dtor
}

int numSquares(int n) {
    int c = (int)sqrt(n);
    vector<int> vs(c+1);
    for(int i=0; i<=c; ++i) {
        vs[i] = i*i;
    }

    vector<int> dp(n+1);
    dp[0] = 1;
    for(int i=1; i<n+1; ++i) {
        int res = INT_MAX;
        for(int j=1; j<=c; ++j) {
            if(i>=vs[j]) {
                //dp[i-vs[j]] +1;
                res = res>dp[i-vs[j]] +1? (dp[i-vs[j]] +1):res;
            } else {
                break;
            }
        }
        dp[i] = res;
    }
    return dp[n];
}

class Solution1 {
public:
    int numSquares(int n) {
        while(n % 4 == 0) n /= 4;  //判4
        if(n % 8 == 7) return 4;

        for(int i = 0; i * i <= n; ++i) {  //判1
            if(n - i * i == 0) return 1;
        }

        for(int i = 0; i * i < n; ++i) {   //判2
            for(int j = 0; j * j < n; ++j) {
                if(n - i * i - j * j == 0) return 2;
            }
        }
        return 3;   //4、1、2，都不是，直接返回3
    }
};
