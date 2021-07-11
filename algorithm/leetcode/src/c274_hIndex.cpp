#include "c274_hIndex.h"

c274_hIndex::c274_hIndex()
{
    //ctor
}

c274_hIndex::~c274_hIndex()
{
    //dtor
}

int c274_hIndex::hIndex(vector<int>& citations)
{
    int ans = 0;;
    sort(citations.begin(), citations.end(), greater<int>());
    for(int i=0; i<citations.size(); ++i) {
        if(citations[i] >= i+1) {
            ans = i+1;
        }
        else {
            break;
        }
    }
    return ans;
}

void c274_hIndex::test()
{
    vector<int> citations = {3, 0, 6, 1, 5};
    cout<<hIndex(citations)<<endl;
    cout<<"hIndex test end"<<endl;

}
