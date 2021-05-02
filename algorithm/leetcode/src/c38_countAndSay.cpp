#include "c38_countAndSay.h"

c38_countAndSay::c38_countAndSay()
{
    //ctor
}

c38_countAndSay::~c38_countAndSay()
{
    //dtor
}

string countAndSay1(int n) {
        vector<string> v;
        v.emplace_back("1");
        v.emplace_back("");

        for(int i=1; i<n; ++i) {
            int c = 1;
            string tmp = "";
            int j=1;
            for(j=1; j<v[(i-1)&0x01].size(); ++j) {
                if(v[(i-1)&0x01][j-1] == v[(i-1)&0x01][j]) {
                    ++c;
                } else {
                    tmp += to_string(c) + v[(i-1)&0x01][j-1];
                    c = 1;
                }
            }
            tmp += to_string(c) + v[(i-1)&0x01][j-1];
            v[i&0x01] = tmp;
        }
        return v[(n-1)&0x01];
    }

string countAndSay2(int n)
{
    string ans = "1";

    for(int i=1; i<n; ++i) {
        int c = 1;
        string tmp = "";
        int j=1;
        for(j=1; j<ans.size(); ++j) {
            if(ans[j] == ans[j-1]) {
                ++c;
            } else {
                //tmp += to_string(c) + ans[j-1];
                tmp += c+'0';
                tmp += ans[j-1];
                c = 1;
            }
        }
        // tmp += to_string(c) + ans[j-1];
        tmp += c+'0';
        tmp += ans[j-1];
        ans = tmp;
    }
    return ans;
}
