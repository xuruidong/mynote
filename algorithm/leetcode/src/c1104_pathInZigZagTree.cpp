#include "c1104_pathInZigZagTree.h"

c1104_pathInZigZagTree::c1104_pathInZigZagTree()
{
    //ctor
}

c1104_pathInZigZagTree::~c1104_pathInZigZagTree()
{
    //dtor
}

vector<int> pathInZigZagTree(int label)
{
    int n = 0;
    int i = 0;
    while(i<32) {
        if(label & (1<<i)) {
            n = i;
        }
        ++i;
    }
    ++n;

    int max_val = 1<<n;
    int step = 1, ind = 1;
    stack<int> stk;
    int dat[max_val];
    memset(dat, 0, max_val);
    int dst_ind = 0;
    for(int i=1; i<=n; ++i) {
        if(i&0x01) {
            while(step < (1<<i)) {
                dat[ind] = step;
                if(step == label) {
                    dst_ind = ind;
                }
                ++ind;
                ++step;
            }
        }
        else {
            while(step < (1<<i)) {
                stk.push(step);
                ++step;
            }
            while(!stk.empty()) {
                dat[ind] = stk.top();
                if(dat[ind] == label) {
                    dst_ind = ind;
                }
                stk.pop();
                ++ind;
            }
        }
    }

    vector<int> ans;
    while(dst_ind>=1) {
        stk.push(dat[dst_ind]);
        dst_ind = dst_ind>>1;
    }
    while(!stk.empty()) {
        ans.emplace_back(stk.top());
        stk.pop();
    }
    return ans;
}
