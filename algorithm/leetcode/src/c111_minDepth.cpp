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
        return 0;
    }
    return min(minDepth(root->left), minDepth(root->right)) + 1;
}
