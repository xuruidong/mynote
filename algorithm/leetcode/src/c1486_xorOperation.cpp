#include "c1486_xorOperation.h"

c1486_xorOperation::c1486_xorOperation()
{
    //ctor
}

c1486_xorOperation::~c1486_xorOperation()
{
    //dtor
}

int xorOperation(int n, int start)
{
    int ans = 0;
    for(int i=0; i<n; ++i) {
        ans ^= start+(i<<1);
    }

    return ans;
}
