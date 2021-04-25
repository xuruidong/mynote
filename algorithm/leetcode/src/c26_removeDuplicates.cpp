class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len < 2){
            return len;
        }
        int fast=0, slow=1;
        for(fast=1; fast<len; ++fast){
            if(nums[fast] != nums[slow-1]){
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};
