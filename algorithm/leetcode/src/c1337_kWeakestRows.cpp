#include "c1337_kWeakestRows.h"

c1337_kWeakestRows::c1337_kWeakestRows()
{
    //ctor
}

c1337_kWeakestRows::~c1337_kWeakestRows()
{
    //dtor
}

vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    vector<pair<int, int>> res;
    for(int j=0; j<mat.size(); ++j) {
        int a = 0;
        for(int i=0; i<mat[j].size(); ++i) {
            if(mat[j][i]) {
                ++a;
            }
            else {
                break;
            }
        }
        res.emplace_back(a, j);
    }
    sort(res.begin(), res.end());
    vector<int> ans;
    k = k>res.size()?res.size():k;
    for(int i=0; i<k; ++i) {
        ans.emplace_back(res[i].second);
    }
    return ans;
}
