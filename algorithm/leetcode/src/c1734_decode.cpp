#include "c1734_decode.h"

c1734_decode::c1734_decode()
{
    //ctor
}

c1734_decode::~c1734_decode()
{
    //dtor
}

vector<int> decode(vector<int>& encoded) {
    vector<int> ans;
    int len = encoded.size();
    int n = len+1;
    int tmp = 0;
    for(int i=1; i<=n; ++i) {
        tmp ^= i;
    }

    int tmp2 = 0;
    for(int i=1; i<len;++i,++i) {
        tmp2 ^= encoded[i];
    }

    int ans_tmp = tmp^tmp2;
    ans.push_back(ans_tmp);
    for(int i=0; i<len;++i) {
        ans_tmp ^= encoded[i];
        ans.push_back(ans_tmp);
    }
    return ans;
}

vector<int> decode2(vector<int>& encoded) {
    vector<int> ans;
    int len = encoded.size();
    int n = len+1;
    int tmp = n%4;
    if(tmp == 0) {
        tmp = n;
    } else if(tmp==2) {
        tmp = n+1;
    } else if(tmp == 3) {
        tmp = 0;
    }

    int tmp2 = 0;
    for(int i=1; i<len;++i,++i) {
        tmp2 ^= encoded[i];
    }

    int ans_tmp = tmp^tmp2;
    ans.push_back(ans_tmp);
    for(int i=0; i<len;++i) {
        ans_tmp ^= encoded[i];
        ans.push_back(ans_tmp);
    }
    return ans;
}
