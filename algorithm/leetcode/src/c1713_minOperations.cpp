#include "c1713_minOperations.h"

c1713_minOperations::c1713_minOperations()
{
    //ctor
}

c1713_minOperations::~c1713_minOperations()
{
    //dtor
}

int minOperations(vector<int>& target, vector<int>& arr)
{
    int tmp[arr.size()+1];
    int len = arr.size()+1;
    int pre = 0, pre1 = 0;
// xxxxxxxxxxxxxxx

    memset(tmp, 0, sizeof(tmp));
    for(int i=0; i<target.size(); ++i) {
        pre = tmp[0];
        pre1 = tmp[1];
        for(int j=1; j<len; ++j) {
            int val = 0;

            if(target[i] == arr[j-1]) {
                val = pre;
            }
            else {
                val = min(pre1, tmp[j]) +1;
            }
            pre = pre1;
            pre1 = tmp[j];
            tmp[j] = val;
        }
    }
    return tmp[len-1];
}
