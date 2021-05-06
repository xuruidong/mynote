#include "c111_minDepth.h"

c111_minDepth::c111_minDepth()
{
    //ctor
}

c111_minDepth::~c111_minDepth()
{
    //dtor
}

int minDepth(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }
    if(root->left==nullptr && root->right==nullptr) {
        return 1;
    }
    if(root->left==nullptr) {
        return minDepth(root->right)+1;
    }
    if(root->right == nullptr) {
        return minDepth(root->left)+1;
    }

    return min(minDepth(root->left), minDepth(root->right)) + 1;
}
