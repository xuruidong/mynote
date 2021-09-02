#include "c165_compareVersion.h"

c165_compareVersion::c165_compareVersion()
{
    //ctor
}

c165_compareVersion::~c165_compareVersion()
{
    //dtor
}


int c165_compareVersion::compareVersion(string version1, string version2)
{
    int ind1 = 0, ind2 = 0;
    int n1 = 0, n2 = 0;

    while(1) {
        n1 = 0;
        n2 = 0;
        for(; ind1<version1.size(); ++ind1) {
            if(version1[ind1] == '.') {
                ++ind1;
                break;
            }
            n1 *= 10;
            n1 += version1[ind1] - '0';
        }

        for(; ind2<version2.size(); ++ind2) {
            if(version2[ind2] == '.') {
                ++ind2;
                break;
            }
            n2 *= 10;
            n2 += version2[ind2] - '0';
        }
        cout<<n1<<"   --   "<<n2<<endl;

        if (n1 > n2) {
            return 1;
        } else if(n1 < n2) {
            return -1;
        }

        if(ind1 >= version1.size() && ind2 >= version2.size()) {
            break;
        }
    }
    return 0;
}

void c165_compareVersion::test()
{
    string s1 = "0.01";
    string s2 = "0.001.2";

    int ret = compareVersion(s1, s2);
    cout<< "compareVersion ans = "<<ret<<endl;
    cout<< "c165_compareVersion test end"<<endl;
}
