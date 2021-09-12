#include "c600_findIntegers.h"

c600_findIntegers::c600_findIntegers()
{
    //ctor
}

c600_findIntegers::~c600_findIntegers()
{
    //dtor
}

//  ---  timeout ----
void process(int n, int cur, int max_ind, int cur_ind, int &ans)
{
    if(cur > n) {
        return;
    }

    if(cur_ind > max_ind) {
        return;
    }

    if (cur != 0 && (cur_ind == max_ind)) {
        ++ans;
        return;
    }
    cur <<= 1;
    ++cur_ind;
    if((cur & 0x02) == 0)
        process(n, cur|0x01, max_ind, cur_ind, ans);
    process(n, cur, max_ind, cur_ind, ans);
}

int findIntegers(int n)
{
    int ind = 0;
    for(int i=0; i<32; ++i) {
        if(n>>i)
            ind = i;
    }

    int ans = 1;
    process(n, 0, ind, 0, ans);
    process(n, 1, ind, 0, ans);
    return ans;
}
