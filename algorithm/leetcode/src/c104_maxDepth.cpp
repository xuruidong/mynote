#include "c104_maxDepth.h"

c104_maxDepth::c104_maxDepth()
{
    //ctor
}

c104_maxDepth::~c104_maxDepth()
{
    //dtor
}

static void recur(TreeNode *root, int depth, int &ans)
{
    if(root == nullptr) {
        return;
    }
    ++depth;
    ans = ans>depth?ans:depth;
    recur(root->left, depth, ans);
    recur(root->right, depth, ans);
}

int maxDepth2(TreeNode* root) {
    int ans = 0;
    int depth = 0;
    recur(root, depth, ans);
    return ans;
}

int maxDepth(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }
    return max(maxDepth(root->left), maxDepth(root->right))+1;
}
