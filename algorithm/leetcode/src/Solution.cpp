#include "Solution.h"
#include <string>
#include <queue>
#include <iostream>

using namespace std;

Solution::Solution()
{
    //ctor
}

Solution::~Solution()
{
    //dtor
}



struct cmp//注意cmp是结构体
{
    bool operator()(string s1,string s2)
    {
        if((s1 + s2) < (s2+s1)){
            //cout<<s1+s2<<endl;
            return true;
        }
        return false;
    }
};

std::string Solution::c179_largestNumber(std::vector<int>& nums)
{
    std::priority_queue<string, vector<string>, cmp> pq;
    std::string res;
    for(auto n:nums){
        pq.push(std::to_string(n));
    }
    while(!pq.empty()){
        if(res == "0"){
            res = pq.top();
        }
        else{
            res += pq.top();
        }
        pq.pop();
    }

    return res;
}


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 /*
int process(TreeNode *root, int &pre, int &minDiff)
{
    if(!root){
        return -1;
    }

    process(root->left, pre, minDiff);
    if(pre != -1){
        minDiff = minDiff < (root->val - pre)? minDiff:(root->val - pre);
    }
    pre = root->val;
    process(root->right, pre, minDiff);
}

int Solution::c783_minDiffInBST(TreeNode* root)
{
    int ret = 0;
    if(process(root, ret) == 0){
        return ret;
    }
    return 0;
}
*/
