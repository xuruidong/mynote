#include "c1035_maxUncrossedLines.h"

c1035_maxUncrossedLines::c1035_maxUncrossedLines()
{
    //ctor
}

c1035_maxUncrossedLines::~c1035_maxUncrossedLines()
{
    //dtor
}

static int process(vector<int>& nums1, vector<int>& nums2, unordered_map<int, vector<int>> &umap, int ind, int n2, int cur_ans, int &ans)
{
    if((vector<int>::size_type)ind >= nums1.size()) {
        ans = max(ans, cur_ans);
        return ans;
    }

    int n1 = nums1[ind];
    for(vector<int>::size_type i=0; i<umap[n1].size(); ++i) {
        if(umap[n1][i] > n2) {
            ++cur_ans;
            process(nums1, nums2, umap, ind+1, umap[n1][i], cur_ans, ans);
            --cur_ans;
        }
    }
    return process(nums1, nums2, umap, ind+1, n2, cur_ans, ans);
}

int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2)
{
    unordered_map<int, vector<int>> umap;
    for(vector<int>::size_type i=0; i<nums2.size(); ++i) {
        umap[nums2[i]].push_back(i);
    }

    int ans=0, cur_ans=0;
    process(nums1, nums2, umap, 0, -1, cur_ans, ans);
    return ans;
}

int maxUncrossedLines2(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> *n1;
    vector<int> *n2;
    int len = 0;
    if(nums1.size()>nums2.size()) {
        n1 = &nums2;
        n2 = &nums1;
    } else {
        n1 = &nums1;
        n2 = &nums2;
    }
    len = min(nums1.size(), nums2.size()) +1;
    /*
    vector<int> dp(len, 0);
    for(int i=0; i<(*n2).size(); ++i) {
        for(int j=(*n1).size()-1; j>=0; --j) {
            if((*n1)[j] == (*n2)[i]) {
                dp[j+1] = dp[j]+1;
            } else {
                dp[j+1] = max(dp[j], dp[j+1]);
            }
        }
    }

    return dp[len-1];
    */
    vector<vector<int>> dp;
    vector<int> tmp(len, 0);
    dp.push_back(tmp);
    dp.push_back(tmp);
    for(vector<int>::size_type i=0; i<(*n2).size(); ++i) {
        for(vector<int>::size_type j=0; j<(*n1).size(); ++j) {
            if((*n1)[j] == (*n2)[i]) {
                dp[(i+1)&0x01][j+1] = dp[i&0x01][j]+1;
            } else {
                dp[(i+1)&0x01][j+1] = max(dp[(i+1)&0x01][j], dp[i&0x01][j+1]);
            }
        }
    }
    return dp[(*n2).size()%2][len-1];
}
