#include "c523_checkSubarraySum.h"

c523_checkSubarraySum::c523_checkSubarraySum()
{
    //ctor
}

c523_checkSubarraySum::~c523_checkSubarraySum()
{
    //dtor
}

bool checkSubarraySum(vector<int>& nums, int k)
{
    unordered_map<int, int> umap;
    vector<int> prefixSum;
    prefixSum.emplace_back(0);
    umap[0] = -1;
    for(int i=0; i<nums.size(); ++i) {
        int v = nums[i]+prefixSum[i];
        prefixSum.emplace_back(v%k);
        auto it = umap.find(v%k);
        if(it != umap.end()) {
            if(it->second - i > 1) {
                return true;
            }
        } else {
            umap[v%k] = i;
        }
    }
    return false;
}
