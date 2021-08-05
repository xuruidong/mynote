#include "c743_networkDelayTime.h"

c743_networkDelayTime::c743_networkDelayTime()
{
    //ctor
}

c743_networkDelayTime::~c743_networkDelayTime()
{
    //dtor
}

int networkDelayTime(vector<vector<int>>& times, int n, int k)
{
    unordered_map<int, int> root_map;
    unordered_map<int, int> umap;
    int start = INT_MIN;
    umap[k] = 0;
    for(int i=0; i<times.size(); ++i) {
        root_map[times[i][1]] = times[i][0];

    }
}
