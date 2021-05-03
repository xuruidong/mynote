#include "c236_lowestCommonAncestor.h"

c236_lowestCommonAncestor::c236_lowestCommonAncestor()
{
    //ctor
}

c236_lowestCommonAncestor::~c236_lowestCommonAncestor()
{
    //dtor
}

static int recur(TreeNode *root, TreeNode* p, TreeNode* q, TreeNode **ans)
{
    if(root == nullptr) {
        return 0;
    }
    /*
    wrong
    if(*ans) {
        return 1;
    }
    */
    if(root->val == p->val || root->val == q->val) {
        if(recur(root->left, p, q, ans) || recur(root->right, p, q, ans)) {
            *ans = root;
        }
        return 1;
    }

    int v1 = recur(root->left, p, q, ans);
    int v2 = recur(root->right, p, q, ans);
    if(v1 && v2) {
        *ans = root;
        return 1;
    }
    return v1 || v2;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    TreeNode *ans = nullptr;
    recur(root, p, q, &ans);
    return ans;
}
