#ifndef C295_MEDIANFINDER_H
#define C295_MEDIANFINDER_H

#include "common.h"

class c295_MedianFinder
{
    public:
        c295_MedianFinder();
        virtual ~c295_MedianFinder();

    protected:

    private:
        priority_queue<int, vector<int>, less<int>> small_eles;
        priority_queue<int, vector<int>, greater<int>> big_eles;
        int eles_count;
};

#endif // C295_MEDIANFINDER_H
