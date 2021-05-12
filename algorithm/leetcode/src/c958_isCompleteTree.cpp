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
    bool null_flag = false;
    q.push(root);
    while(!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();

        if(null_flag == true) {
            if(cur->left || cur->right) {
                return false;
            }
        }
        if(cur->left)
            q.push(cur->left);
        else {
            null_flag = true;
        }

        if(null_flag == true) {
            if(cur->right) {
                return false;
            }
        } else {
            if(cur->right)
                q.push(cur->right);
            else {
                null_flag = true;
            }
        }
    }
    return true;
}
