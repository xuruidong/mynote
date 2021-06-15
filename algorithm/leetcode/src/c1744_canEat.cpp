#include "c1744_canEat.h"

c1744_canEat::c1744_canEat()
{
    //ctor
}

c1744_canEat::~c1744_canEat()
{
    //dtor
}

vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries)
{
    vector<long long> sum;
    sum.push_back(0);
    for(int i=0; i<candiesCount.size(); ++i) {
        sum.push_back(sum[i] + candiesCount[i]);
    }

    vector<bool> ans;
    for(auto &q:queries) {
        long long v1 = q[1] * q[2];
        if(( v1 > sum[q[0]]) || (q[2] <= sum[q[0]+1])) {
            ans.push_back(true);
        } else {
            ans.push_back(false);
        }
    }
    return ans;
}
