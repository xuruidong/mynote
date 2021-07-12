#include "c275_hIndex.h"

c275_hIndex::c275_hIndex()
{
    //ctor
}

c275_hIndex::~c275_hIndex()
{
    //dtor
}

int hIndex(vector<int>& citations)
{
    int ans = 0;
    int left = 0, right = citations.size()-1;
    int mid = 0;
    while(left <= right) {
        mid = left + ((right - left)>>1);
        if(citations[mid] >= mid+1) {
            right = mid;
            ans = citations.size() - mid;
        }
        else {
            left = mid+1;
        }
    }
    return ans;
}
