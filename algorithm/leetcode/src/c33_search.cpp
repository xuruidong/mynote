#include "Solution.h"

bool Solution::c33_search(std::vector<int>& nums, int target)
{
    int len = nums.size();
    if(len < 1){
        return -1;
    }
    int left = 0;
    int right = len-1;
    int mid = ((right-left)>>1) +left;
    while(mid>left){
        if(nums[mid] == target){
            return mid;
        }
        if(target < nums[mid]){
            if(nums[left] < target){
                // nums[left] < target < nums[mid]
                right = mid;
            }
            else if(nums[mid] < nums[left]){
                // target < nums[mid] < nums[left]
                left = mid;
            }
            else{
                // target < nums[left] < nums[mid]
                left = mid;
            }
        }
        else{
            //  nums[mid] < target < nums[right]
            //  nums[mid] < nums[right] < target
            //  nums[right] < nums[mid] < target
            if(target < nums[right]){
                left = mid;
            }
            else if (nums[mid] < nums[right]){
                right = mid;
            }
            else{
                left = mid;
            }
        }
        mid = ((right-left)>>1) +left;
    }
    if(target == nums[left]){
        return left;
    }
    if(target == nums[right]){
        return right;
    }
    return -1;
}
