#include "c1838_maxFrequency.h"

c1838_maxFrequency::c1838_maxFrequency()
{
    //ctor
}

c1838_maxFrequency::~c1838_maxFrequency()
{
    //dtor
}

int maxFrequency(vector<int>& nums, int k)
{
    /*
    int ans = 0;
    int ans_tmp = 0;
    int k_tmp = k;
    sort(nums.begin(), nums.end());
    for(int i=nums.size()-1; i>0; --i) {
        if(nums[i] == nums[i-1]) {
            ++ans_tmp;
        }
        for(int j=i; j=0; --j) {
            int tmp = nums[i] - nums[j-1];
            if(k_tmp >= tmp) {
                k_tmp -= tmp;
                ++ans_tmp;
            }
        }
    }

    return ans;
    */
    int ans = 1;
    int l=0, r=1;
    long long totals = 0;
    sort(nums.begin(), nums.end());
    for(int i=1; i<nums.size(); ++i) {
        r = i;
        totals += (long long)(r-l)*(nums[r]-nums[r-1]);
        while(totals > k) {
            totals -= nums[l];
            ++l;
        }
        ans = max(ans, r-l+1);
    }
    return ans;
}

// before
#if 0
int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int ans = 1;
    int left = 0;
    int sum = 0;
    for(int i=1; i<nums.size(); ) {
        if(nums[i-1] < nums[i]) {
            int delt = nums[i] - nums[i-1];

            if(sum + (i-left+1)*delt > k) {
                //ans = ans>(i-left+1)?ans:(i-left+1);
                ans = ans>(i-left)?ans:(i-left);
                sum -= nums[i-1] - nums[left];
                ++left;
            } else {
                ans = ans>(i-left+1)?ans:(i-left+1);
                sum += (i-left+1)*delt;
                ++i;
            }
        } else {
            ans = ans>(i-left+1)?ans:(i-left+1);
            ++i;
        }
    }

    return ans;
}
#endif
