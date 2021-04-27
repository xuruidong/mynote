#include "c983_rangeSumBST.h"

c983_rangeSumBST::c983_rangeSumBST()
{
    //ctor
}

c983_rangeSumBST::~c983_rangeSumBST()
{
    //dtor
}

static void recur(TreeNode *root, int low, int high, int &ans)
{
    if(root == nullptr) {
        return;
    }
    recur(root->left, low, high, ans);
    if(root->val <= high && root->val >= low) {
        ans += root->val;
    }
    recur(root->right, low, high, ans);
}

int c983_rangeSumBST::rangeSumBST(TreeNode* root, int low, int high)
{
    int ans = 0;
    recur(root, low, high, ans);
    return ans;
}

int c983_rangeSumBST::rangeSumBST2(TreeNode* root, int low, int high)
{
    int ans = 0;
    std::stack<TreeNode *> stk;
    TreeNode *cur = root;
    while(1) {
        if(cur) {
            stk.push(cur);
            cur = cur->left;
        } else if(!stk.empty()) {
            cur = stk.top();
            if(cur->val >= low && cur->val <= high) {
                ans += cur->val;
            }
            stk.pop();
            cur = cur->right;  // ÈÝÒ×Íü
        } else {
            break;
        }
    }
    return ans;
}
