#include "c421_findMaximumXOR.h"

c421_findMaximumXOR::c421_findMaximumXOR()
{
    //ctor
}

c421_findMaximumXOR::~c421_findMaximumXOR()
{
    //dtor
}

class trie {
    trie *t0;
    trie *t1;

public:
    trie () {
        t0 = nullptr;
        t1 = nullptr;
    }

    void add(int val) {
        trie *cur = this;
        for(int i=30; i>=0; --i) {
            int tmp = val >> i;
            if(tmp & 0x01) {
                if(!cur->t1)
                    cur->t1 = new trie;
                cur = cur->t1;
            } else {
                if(!cur->t0)
                    cur->t0 = new trie;
                cur = cur->t0;
            }
        }
    }

    int search_max_xor(int val) {
        trie *cur = this;
        int ans = 0;
        for(int i=30; i>=0; --i) {
            int tmp = val >> i;
            if(tmp & 0x01) {
                //cout<<i<<endl;
                if(cur->t0) {
                    cur = cur->t0;
                    ans += (1<<i);
                } else {
                    cur = cur->t1;
                }
            } else {
                //cout<<"==="<<i<<endl;
                if(cur->t1) {
                    cur = cur->t1;
                    ans += (1<<i);
                } else {
                    cur = cur->t0;
                }
            }
        }
        return ans;
    }
};

int findMaximumXOR(vector<int> &nums)
{
    trie t;
    int ans = 0;
    for(int n:nums) {
        t.add(n);
        ans = max(ans, t.search_max_xor(n));
    }
    return ans;
}
