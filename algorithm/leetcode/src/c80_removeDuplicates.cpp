#include "Solution.h"

int Solution::c80_removeDuplicates(vector<int>& nums)
{
    int len = nums.size();
    if(len<=2){
        return len;
    }
    int slow = 0;
    int cur = 0;
    int fast = 2;

    while(fast<len){
        if(nums[cur] == nums[fast])
        {
            nums[slow++] = nums[cur++];
            nums[slow++] = nums[cur++];
            while(++fast < len && nums[cur] == nums[fast]);
            if(fast>=len){
                return slow;
            }
            cur = fast;
            fast += 2;
        }
        else{
            nums[slow++] = nums[cur++];
            ++fast;
        }
    }
    while(cur<len){
        nums[slow++] = nums[cur++];
    }
    return slow;
}

int Solution::c80_removeDuplicates2(vector<int>& nums)
{
    int len = nums.size();
    if(len<=2){
        return len;
    }

    int slow = 2, fast = 2;
    for(;fast<len; ++fast){
        if(nums[slow-2] != nums[fast]){
            nums[slow++] = nums[fast];
        }
    }
    return slow;
}
