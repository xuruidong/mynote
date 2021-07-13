#include "c218_getSkyline.h"

c218_getSkyline::c218_getSkyline()
{
    //ctor
}

c218_getSkyline::~c218_getSkyline()
{
    //dtor
}

vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
{
    vector<vector<int>> ans;
    vector<pair<int, int>> boundaries;
    multiset<int> heigh_set;

    for(auto &b:buildings) {
        boundaries.emplace_back(b[0], -b[2]);
        boundaries.emplace_back(b[1], b[2]);
    }
    sort(boundaries.begin(), boundaries.end());

    int prev_heigh = 0, cur_heigh = 0;
    heigh_set.insert(0);

    for(auto &b:boundaries) {
        if(b.second < 0) {
            heigh_set.insert(-b.second);
        }
        else {
            heigh_set.erase(heigh_set.find(b.second));
        }
        cur_heigh = *heigh_set.rbegin();
        if(cur_heigh != prev_heigh) {
            ans.push_back({b.first, cur_heigh});
            prev_heigh = cur_heigh;
        }
    }
    return ans;
}
