#include "c1011_shipWithinDays.h"

c1011_shipWithinDays::c1011_shipWithinDays()
{
    //ctor
}

c1011_shipWithinDays::~c1011_shipWithinDays()
{
    //dtor
}

int shipWithinDays(vector<int>& weights, int D)
{
    int left = *max_element(weights.begin(), weights.end());
    int right = accumulate(weights.begin(), weights.end(), 0);

    while(left<right) {
        int mid = ((right-left)>>1)+left;

        int sum = 0;
        int day = 0;
        for(auto w:weights) {
            if(sum + w > mid) {
                sum = 0;
                ++day;
            }
            sum += w;
        }
        if(day > D) {
            left = mid+1;
        } else {
            right = mid;
        }
    }
    return left;
}
