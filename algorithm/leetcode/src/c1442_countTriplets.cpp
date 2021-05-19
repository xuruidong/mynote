#include "c1442_countTriplets.h"

c1442_countTriplets::c1442_countTriplets()
{
    //ctor
}

c1442_countTriplets::~c1442_countTriplets()
{
    //dtor
}

int countTriplets(vector<int> &arr)
{
    vector<int> xsum;
    int ans=0;
    int len = arr.size();
    xsum.push_back(0);
    for(int i=0; i<len; ++i) {
        xsum.push_back(arr[i] ^ xsum[i]);
    }

    for(int i=0; i<len-1; ++i) {
        for(int j=i+1; j<len; ++j) {
            int s1 = xsum[i]^xsum[j];
            for(int k=j; k<len; ++k) {
                if((xsum[j]^xsum[k+1]) == s1) {
                    ++ans;
                }
            }
        }
    }
    return ans;
}

int countTriplets2(vector<int> &arr)
{
    int ans=0;
    int tmp = 0;
    unordered_map<int, set<int>> umap;
    umap[0].insert(-1);
    for(int i=0; i<arr.size(); ++i) {
        tmp ^= arr[i];
        umap[tmp].insert(i);
    }
/*
    for(auto &it : umap) {
        for(auto &sit = it.second.begin(); sit != it.second.end(); ++sit) {
            for(auto &sit2 = sit+1; sit2 != it.second.end(); ++sit2) {
                if(*sit +1 != *sit2) {
                    ans += (*sit2 - *sit - 1);
                }
            }
        }
    }
*/
    return ans;
}
