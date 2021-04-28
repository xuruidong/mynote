#include "c633_judgeSquareSum.h"

c633_judgeSquareSum::c633_judgeSquareSum()
{
    //ctor
}

c633_judgeSquareSum::~c633_judgeSquareSum()
{
    //dtor
}

bool judgeSquareSum(int c)
{
    int left = 0;
    int right = int(sqrt(c));
    int tmp = 0;
    while(left <= right) {
        tmp = left*left + right*right;
        if(tmp == c) {
            return true;
        } else if(tmp < c) {
            ++left;
        } else {
            --right;
        }
    }

    return false;
}
