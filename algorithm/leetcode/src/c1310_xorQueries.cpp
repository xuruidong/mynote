#include "c1310_xorQueries.h"

c1310_xorQueries::c1310_xorQueries()
{
    //ctor
}

c1310_xorQueries::~c1310_xorQueries()
{
    //dtor
}

vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries)
{
    vector<int> sum(arr.size());
    sum[0] = arr[0];
    for(int i=1; i<sum.size(); ++i) {
        sum[i] = sum[i-1] ^ arr[i];
    }

    vector<int> ans;
    for(int i=0; i<queries.size(); ++i) {
        if (queries[i][0] == 0){
            ans.push_back(sum[queries[i][1]]);
        } else {
            ans.push_back(sum[queries[i][1]] ^ sum[queries[i][0]-1]);
        }
    }
    return ans;
}

vector<int> xorQueries2(vector<int>& arr, vector<vector<int>>& queries)
{
    for(int i=1; i<arr.size(); ++i) {
        arr[i] ^= arr[i-1];
    }

    vector<int> ans(queries.size());
    for(int i=0; i<queries.size(); ++i) {
        if (queries[i][0] == 0){
            ans[i] = arr[queries[i][1]];
        } else {
            ans[i] = arr[queries[i][1]] ^ arr[queries[i][0]-1];
        }
    }
    return ans;
}
