#include "c295_MedianFinder.h"

c295_MedianFinder::c295_MedianFinder()
{
    //ctor
    eles_count = 0;
}

c295_MedianFinder::~c295_MedianFinder()
{
    //dtor
}


void addNum(int num)
{
    if(eles_count == 0) {
        small_eles.push(num);
        ++eles_count;
        return;
    }

    int tmp = small_eles.top();
    if(num < tmp) {
        small_eles.push(num);
    } else {
        big_eles.push(num);
    }

    // adjust
    int slen = small_eles.size();
    int blen = big_eles.size();
    while(slen - blen > 1) {
        big_eles.push(small_eles.top());
        small_eles.pop();
        --slen;
        ++blen;
    }

    while(blen - slen > 1) {
        small_eles.push(big_eles.top());
        big_eles.pop();
        --blen;
        ++slen;
    }

    ++eles_count;
}

double findMedian()
{
    if(eles_count == 1) {
        return (double)small_eles.top();
    }

    if(eles_count %2) {
        int ret = small_eles.size() > big_eles.size()?small_eles.top():big_eles.top();
        return (double)ret;
    }
    return ((double)small_eles.top() + (double)big_eles.top())/2.0;
}
