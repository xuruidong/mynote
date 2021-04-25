#include "c897_increasingBST.h"

c897_increasingBST::c897_increasingBST()
{
    //ctor
}

c897_increasingBST::~c897_increasingBST()
{
    //dtor
}

static TreeNode *recur(TreeNode* root, TreeNode** head)
{
    if(!root) {
        return nullptr;
    }

    TreeNode *p = recur(root->left, head);
    if(p) {
        p->right = root;
    } else {
        if(!head) {
            head = &root;
        }
    }

    root->right = recur(root->right, head);
    return root;
}

TreeNode* increasingBST(TreeNode* root)
{
    TreeNode **ret = nullptr;
    recur(root, ret);
    return *ret;
}
