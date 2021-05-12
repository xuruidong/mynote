#include "c958_isCompleteTree.h"

c958_isCompleteTree::c958_isCompleteTree()
{
    //ctor
}

c958_isCompleteTree::~c958_isCompleteTree()
{
    //dtor
}

bool isCompleteTree(TreeNode* root)
{
    std::queue<TreeNode*> q;
    if(root == nullptr) {
        return false;
    }
    q.push(root);
    while(!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        if(!cur->left && cur->right) {
            return false;
        }

        if(cur->right == nullptr) {
            if(!q.empty()) {
                return false;
            }
        }
        if(cur->left)
            q.push(cur->left);

        if(cur->right)
            q.push(cur->right);
    }
    return true;
}
