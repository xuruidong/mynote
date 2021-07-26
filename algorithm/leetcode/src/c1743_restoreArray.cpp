#include "c1743_restoreArray.h"

c1743_restoreArray::c1743_restoreArray()
{
    //ctor
}

c1743_restoreArray::~c1743_restoreArray()
{
    //dtor
}

vector<int> restoreArray(vector<vector<int>>& adjacentPairs)
{
    unordered_set<int> uset;
    unordered_map<int,  vector<int>> umap;

    for (auto &p:adjacentPairs) {
        umap[p[0]].emplace_back(p[1]);
        umap[p[1]].emplace_back(p[0]);
        if(umap[p[0]].size() == 1) {
            uset.insert(p[0]);
        } else {
            uset.erase(p[0]);
        }
        if(umap[p[1]].size() == 1) {
            uset.insert(p[1]);
        } else {
            uset.erase(p[1]);
        }
    }

    vector<int> ans;
    int pre = *uset.begin();
    ans.emplace_back(pre);
    int next = umap[pre][0];
    ans.emplace_back(next);
    while(1) {
        if(umap[next][0] != pre) {
            pre = next;
            next = umap[next][0];
        } else if(umap[next].size() > 1){
            pre = next;
            next = umap[next][1];
        } else {
            break;
        }
        ans.emplace_back(next);
    }
    return ans;
}
