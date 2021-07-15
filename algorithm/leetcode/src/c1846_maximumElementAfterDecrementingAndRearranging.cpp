#include "c1846_maximumElementAfterDecrementingAndRearranging.h"

c1846_maximumElementAfterDecrementingAndRearranging::c1846_maximumElementAfterDecrementingAndRearranging()
{
    //ctor
}

c1846_maximumElementAfterDecrementingAndRearranging::~c1846_maximumElementAfterDecrementingAndRearranging()
{
    //dtor
}

int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    arr[0] = 1;
    for(int i =1; i<arr.size(); ++i) {
        int exp = arr[i-1] + 1;
        if(arr[i] > exp) {
            arr[i] = exp;
        }
    }
    return arr[arr.size()-1];
}
