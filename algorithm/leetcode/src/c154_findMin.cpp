#include "Solution.h"

int Solution::findMin(vector<int> &nums)
{
    int left = 0;
    int right = nums.size() -1;
    int mid = 0;

    while(right > left+1){
        mid = left + ((right - left)>>1);
        if(nums[left] == nums[mid] && nums[right] == nums[mid]){
            ++left;
            --right;
            continue;
        }
        if(nums[mid] > nums[right]){
            left = mid;
        }
        else{
            right = mid;
        }
    }
    return nums[left]>nums[right]?nums[right]:nums[left];
}
