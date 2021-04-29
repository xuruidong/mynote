#include "c403_canCross.h"

c403_canCross::c403_canCross()
{
    //ctor
}

c403_canCross::~c403_canCross()
{
    //dtor
}

bool c403_canCross::canCross(vector<int>& stones)
{
    int len = stones.size();
    if(stones[0] != 0 || stones[1] != 1) {
        return false;
    }
    unordered_set<int> stones_set;
    for(auto s:stones) {
        stones_set.insert(s);
    }

    unordered_map<int, unordered_set<int>> umap;
    umap[1].insert(0);

    for(int i=1; i<len; ++i) {
        auto it = umap.find(stones[i]);
        if(it != umap.end()) {
            for(auto &v: it->second) {
                int step = stones[i] - v;
                for(int j=step-1; j<=step+1; ++j){

                    //if(j > 0) {
                        if(stones[i] + j == stones[len-1]) {
                            return true;
                        } else if(stones[i] + j < stones[len-1]) {
                            if(stones_set.find(stones[i] + j) != stones_set.end()) {
                                umap[stones[i]+j].insert(stones[i]);
                            }
                            //cout<<stones[i] + j;
                        }
                    //}
                }
                //cout<<endl;
            }
        }
    }
    return false;
}
