#include "c342_isPowerOfFour.h"

c342_isPowerOfFour::c342_isPowerOfFour()
{
    //ctor
}

c342_isPowerOfFour::~c342_isPowerOfFour()
{
    //dtor
}

bool isPowerOfFour(int n)
{
    if((n>0) && (n&(n-1))) {
        while(n) {
            if((n&0x01) || (n&0x4)) {
                return true;
            }
            n >>= 4;
        }
    }
    return false;
}
