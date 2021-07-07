#include "c1711_countPairs.h"

c1711_countPairs::c1711_countPairs()
{
    //ctor
}

c1711_countPairs::~c1711_countPairs()
{
    //dtor
}

int c1711_countPairs::countPairs(vector<int>& deliciousness)
{
    int ans = 0;
    unordered_map<int, int> umap;
    int s[22] = {0};
    for(int i=0; i<sizeof(s)/sizeof(int); ++i) {
        s[i] = 1<<i;
    }

    for(auto &d:deliciousness) {
        for(int i=0; i<22; ++i) {
            auto it = umap.find(s[i]-d);
            if(it != umap.end()) {
                ans += it->second;
                ans %= 1000000007;
            }
        }
        ++umap[d];
    }
    return ans%1000000007;
}

void c1711_countPairs::test()
{
    //vector<int> deli = {1,1,1,3,3,3,7};  //15
    vector<int> deli = {149,107,1,63,0,1,6867,1325,5611,2581,39,89,46,18,12,20,22,234};  //12
    int ret = countPairs(deli);
    cout<<"c1711 test :"<<ret<<endl;
}
