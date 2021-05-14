#include "c826_maxProfitAssignment.h"

c826_maxProfitAssignment::c826_maxProfitAssignment()
{
    //ctor
}

c826_maxProfitAssignment::~c826_maxProfitAssignment()
{
    //dtor
}

/*

[85,47,57]
[24,66,99]
[40,25,25]

0
*/
int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker)
{
    std::map<int, int> tmap;
    vector<vector<int>> vec;
    int len = difficulty.size();
    for(int i=0; i<len; ++i) {
        vec.push_back({difficulty[i], profit[i]});
    }
    sort(vec.begin(), vec.end());
    int cur_max_pro= INT_MIN;
    for(int i=0; i<len; ++i) {
        cur_max_pro = max(cur_max_pro, vec[i][1]);
        tmap[vec[i][0]] = cur_max_pro;
    }

    cur_max_pro = 0;
    for(int i=0; i<worker.size(); ++i) {
        auto it = tmap.upper_bound(worker[i]);
        if (it != tmap.begin())
            --it;
        if(it->first <= worker[i]) {
            cur_max_pro += it->second;
        }
    }
    return cur_max_pro;
}
