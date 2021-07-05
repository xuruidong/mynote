#include "c852_peakIndexInMountainArray.h"

c852_peakIndexInMountainArray::c852_peakIndexInMountainArray()
{
    //ctor
}

c852_peakIndexInMountainArray::~c852_peakIndexInMountainArray()
{
    //dtor
}

int c852_peakIndexInMountainArray::peakIndexInMountainArray(vector<int>& arr)
{
    int left = 0;
    int right = arr.size()-1;
    int mid = 0;
    int ans = 0;
    while(left < right){
        mid = left + ((right-left)>>1);
        if(arr[mid] < arr[left]) {
            right = mid;
        } else if(arr[mid] < arr[right]) {
            left = mid+1;
        } else {
            ans = left;
            cout<<ans<<endl;
            for(int i=left+1; i<=right; ++i) {
                if(arr[ans] < arr[i]) {
                    ans = i;
                } else {
                    cout<<"----"<<ans<<endl;
                    return ans;
                }
            }
            return ans;
        }
    }
    return arr[left]>arr[right]?left:right;
}

void c852_peakIndexInMountainArray::test()
{
    vector<int> nums = {24,69,100,99,79,78,67,36,26,19};
    cout<<"c852_peakIndexInMountainArray test start..."<<endl;
    cout<<peakIndexInMountainArray(nums)<<endl;
    cout<<"c852_peakIndexInMountainArray test end"<<endl;

}
