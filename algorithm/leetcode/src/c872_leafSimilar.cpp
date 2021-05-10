#include "c872_leafSimilar.h"

c872_leafSimilar::c872_leafSimilar()
{
    //ctor
}

c872_leafSimilar::~c872_leafSimilar()
{
    //dtor
}

static void dfs(TreeNode * root, vector<int> &seq)
{
    if(root == nullptr) {
        return;
    }
    dfs(root->left, seq);
    if(!root->left && !root->right) {
        seq.push_back(root->val);
        return;
    }
    dfs(root->right, seq);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> seq1, seq2;
    dfs(root1, seq1);
    dfs(root2, seq2);
    return seq1 == seq2;
}

static void process(TreeNode *root, vector<int> &seq)
{
    std::stack<TreeNode *> stk;
    while(root || !stk.empty()) {
        if(root) {
            stk.push(root);
            root = root->left;
        } else {
            root = stk.top();
            stk.pop();
            if(!root->left && !root->right) {
                seq.push_back(root->val);
            }
            root = root->right;
        }
    }
}

bool leafSimilar2(TreeNode* root1, TreeNode* root2) {
    vector<int> seq1, seq2;
    process(root1, seq1);
    process(root2, seq2);
    return seq1 == seq2;
}

