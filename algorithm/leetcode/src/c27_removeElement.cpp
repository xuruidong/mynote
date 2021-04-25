#include "c27_removeElement.h"

c27_removeElement::c27_removeElement()
{
    //ctor
}

c27_removeElement::~c27_removeElement()
{
    //dtor
}

int c27_removeElement::removeElement(vector<int>& nums, int val)
{
    int len = nums.size();
    int slow=0, fast=0;
    for(; fast<len; ++fast){
        if(nums[fast] != val){
            nums[slow++] = nums[fast];
        }
    }
    return slow;
}

int c27_removeElement::removeElement2(vector<int>& nums, int val)
{
    int left=0, right=nums.size();
    while(left<right){
        if(nums[left] == val){
            nums[left] = nums[--right];
        }
        else{
            ++left;
        }
    }
    return left;
}
