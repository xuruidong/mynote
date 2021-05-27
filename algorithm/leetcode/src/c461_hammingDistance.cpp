#include "c461_hammingDistance.h"

c461_hammingDistance::c461_hammingDistance()
{
    //ctor
}

c461_hammingDistance::~c461_hammingDistance()
{
    //dtor
}

int hammingDistance(int x, int y)
{
    int ans = 0;
    x ^= y;

    while(x) {
        ++ans;
        x = x&(x-1);
    }
    return ans;
}

int hammingDistance2(int x, int y)
{
    int ans = 0;
    int tmp = 1;

    for(int i=0; i<31; ++i) {
        tmp = 1<<i;
        if((x&tmp) != (y&tmp)) {
            ++ans;
        }
    }
    return ans;
}
