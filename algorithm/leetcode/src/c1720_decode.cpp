#include "c1720_decode.h"

c1720_decode::c1720_decode()
{
    //ctor
}

c1720_decode::~c1720_decode()
{
    //dtor
}

vector<int> decode(vector<int>& encoded, int first)
{
    vector<int> ans(encoded.size()+1);
    ans[0] = first;
    for(int i=0; i<encoded.size(); ++i) {
        ans[i+1] = ans[i]^encoded[i];
    }
    return ans;
}

vector<int> decode2(vector<int>& encoded, int first)
{
    vector<int> ans;
    ans.push_back(first);
    for(int i=0; i<encoded.size(); ++i) {
        ans.push_back(ans[i]^encoded[i]);
    }
    return ans;
}
