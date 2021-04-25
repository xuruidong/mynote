

bool Solution::search(vector<int>& nums, int target)
{
    int len = nums.size();
    if(len < 1){
        return false;
    }
    int left = 0;
    int right = len-1;
    int mid = ((right-left)>>1) +left;
    while(mid>left){
        if(nums[mid] == target){
            return true;
        }
        if(target < nums[mid]){
            right = mid;
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
        return true;
    }
    if(target == nums[right]){
        return true;
    }
    return false;
}
