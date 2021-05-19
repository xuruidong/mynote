#include "c993_isCousins.h"

c993_isCousins::c993_isCousins()
{
    //ctor
}

c993_isCousins::~c993_isCousins()
{
    //dtor
}

static void recur(TreeNode *root, int depth, int root_val, unordered_map<int, vector<int>> &umap)
{
    if(!root) {
        return;
    }
    recur(root->left, depth+1, root->val, umap);
    umap[root->val] = {depth, root_val};
    recur(root->right, depth+1, root->val, umap);
}

bool isCousins(TreeNode* root, int x, int y) {
    unordered_map<int, vector<int>> umap;
    recur(root, 0, 0, umap);
    return umap[x][0] == umap[y][0] && umap[x][1] != umap[y][1];
}

static bool dfs(TreeNode* root, int x, int y, int depth, int root_val)
{
    static TreeNode *father = nullptr;
    static int other_depth = 0;
    if(!root) {
        return false;
    }
//    xxxxx
    if(root->val == x || root->val == y) {
        if(father) {
            return depth == other_depth && father->val != root_val;
        } else {
            father = root;
            other_depth = depth;
        }
    }
    return dfs(root->left, x, y, depth+1, root->val) || dfs(root->right, x, y, depth+1, root->val);
}

bool isCousins2(TreeNode* root, int x, int y) {
    return dfs(root, x, y, 0, 0);
}
