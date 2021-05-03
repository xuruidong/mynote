#include "c7_reverse.h"

c7_reverse::c7_reverse()
{
    //ctor
}

c7_reverse::~c7_reverse()
{
    //dtor
}

int c7_reverse::reverse(int x)
{
    int ans = 0;
    int tmp = 0;
    while(x) {
        if(ans > INT_MAX/10 || ans < INT_MIN/10) {
            return 0;
        }
        ans = ans*10;
        tmp =  x%10;
        /*
        do not need
        if((tmp>=0 && ans > INT_MAX-tmp) || (tmp <0 && ans < INT_MIN-tmp)) {
            return 0;
        }
        */
        ans += tmp;
        x /= 10;
    }
    return ans;
}

void c7_reverse::test()
{
    int testdata[] = {2147483642, INT_MAX, 2147483612, 2147483412, INT_MIN, -2147483642, -2147483412,-123, 0, 1200, 1463847412, 2147483647};
    cout<<"=== c7_reverse test: ==="<<endl;
    for(int v:testdata) {
        cout<<v<<"\t\t\t"<<reverse(v)<<endl;
    }
    cout<<"=== c7_reverse test end ==="<<endl;
}
