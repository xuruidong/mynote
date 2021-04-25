/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution1 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return root;
        }
        TreeNode * tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
        return root;
    }

    TreeNode* invertTree2(TreeNode* root) {
        if(!root){
            return root;
        }
        stack<TreeNode *> stk;
        TreeNode* cur = root;
        TreeNode * tmp = nullptr;
        stk.push(root);
        while(!stk.empty()){
            cur = stk.top();
            if(!cur){
                stk.pop();
                continue;
            }
            stk.pop();
            tmp = cur->left;
            cur->left = cur->right;
            cur->right = tmp;

            if(cur->right)
                stk.push(cur->right);
            if(cur->left)
                stk.push(cur->left);
        }
        return root;
    }
};
