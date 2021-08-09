#include "c457_circularArrayLoop.h"

c457_circularArrayLoop::c457_circularArrayLoop()
{
    //ctor
}

c457_circularArrayLoop::~c457_circularArrayLoop()
{
    //dtor
}

bool circularArrayLoop(vector<int>& nums)
{
    if(nums.size() < 1) {
        return false;
    }
    char mp[nums.size()];
    bool f = false;
    int last_ind = 0, next_ind = 0;
    for(int i = 0; i < nums.size(); ++i) {
        memset(mp, 0, sizeof(mp));
        last_ind = i;
        mp[last_ind] = 1;
        f = nums[last_ind]>0?true:false;
        for(;;) {
            next_ind = (last_ind+nums[last_ind]+nums.size())%nums.size();
            bool f_tmp = nums[next_ind]>0?true:false;
            if (f_tmp != f) {
                break;
            }
            if(next_ind == last_ind) {
                //return false;
                break;
            }
            if(mp[next_ind]) {
                return true;
            }
            mp[next_ind] = 1;
            last_ind = next_ind;
        }
    }
    return false;
}
