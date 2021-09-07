#include "c1221_balancedStringSplit.h"

c1221_balancedStringSplit::c1221_balancedStringSplit()
{
    //ctor
}

c1221_balancedStringSplit::~c1221_balancedStringSplit()
{
    //dtor
}

int c1221_balancedStringSplit::balancedStringSplit(string s)
{
    int r = 0, l = 0;
    int ans = 0;
    for (int i=0; i<s.size(); ++i) {
        if (s[i] == 'R') {
            ++r;
        }
        else if (s[i] == 'L') {
            ++l;
        }
        if (r == l) {
            ++ans;
        }
    }
    return ans;
}
