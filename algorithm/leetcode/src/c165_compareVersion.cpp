#include "c165_compareVersion.h"

c165_compareVersion::c165_compareVersion()
{
    //ctor
}

c165_compareVersion::~c165_compareVersion()
{
    //dtor
}


int compareVersion(string version1, string version2)
{
    int ind1 = 0, ind2 = 0;
    int n1 = 0, n2 = 0;
    string s1, s2;
    while(1) {
        for(int i=ind1; i<version1.size(); ++i) {
            if(version1[i] == '.') {
                s1 = version1.substr(ind1, i-ind1);
                ind1 = i+1;
                break;
            }
        }
        for(int i=ind2; i<version2.size(); ++i) {
            if(version2[i] == '.') {
                s2 = version2.substr(ind2, i-ind2);
                ind2 = i+1;
                break;
            }
        }
        n1 = stoi(s1);
        n2 = stoi(s2);
        if (n1 > n2) {
            return 1;
        } else if(n1 < n2) {
            return -1;
        }
        s1 = "";
        s2 = "";
        if(ind1 >= version1.size() && ind2 >= version2.size()) {
            break;
        }
    }
    return 0;
}
