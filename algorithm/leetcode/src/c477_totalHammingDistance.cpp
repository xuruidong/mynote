#include "c477_totalHammingDistance.h"

c477_totalHammingDistance::c477_totalHammingDistance()
{
    //ctor
}

c477_totalHammingDistance::~c477_totalHammingDistance()
{
    //dtor
}

int totalHammingDistance(vector<int>& nums)
{
    int ans = 0;
    int cnt[32] = {0};
    for(int i=0; i<30; ++i) {
        int tmp = 1<<i;
        int sum = 0;
        for(int j=0; j<nums.size(); ++j) {
            sum += ((nums[j] & tmp) == tmp);
        }
        cnt[i] = sum;
    }
    for(int i=0; i<30; ++i) {
        ans += cnt[i]*(nums.size()-cnt[i]);
    }
    return ans;
}
