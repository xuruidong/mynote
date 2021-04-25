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
    TreeNode *head = nullptr;
    TreeNode *tail = nullptr;
    TreeNode *cur = root;
    if(!cur) {
        return cur;
    }
    std::stack<TreeNode *> stk;
    std::vector<TreeNode *> v;
    while(cur || !stk.empty()) {
        if(cur) {
            stk.push(cur);
            cur = cur->left;
        } else {
            cur = stk.top();
            v.push_back(cur);
            /*
            if(!head) {
                head = cur;
            } else {
                tail->right = cur;
            }
            tail = cur;
            */
            stk.pop();
            cur = cur->right;
        }
    }
    head = v[0];
    tail = v[0];
    for(int i=1; i<v.size(); ++i) {
        tail->right = v[i];
        tail->left = nullptr;
        tail = v[i];
    }
    tail->right = nullptr;
    tail->left = nullptr;

    return head;
}

TreeNode* increasingBST2(TreeNode* root)
{
    TreeNode *head = nullptr;
    TreeNode *tail = nullptr;
    TreeNode *cur = root;
    if(!cur) {
        return cur;
    }
    std::stack<TreeNode *> stk;
    while(cur || !stk.empty()) {
        if(cur) {
            stk.push(cur);
            cur = cur->left;
        } else {
            cur = stk.top();
            if(!head) {
                head = cur;
            } else {
                tail->right = cur;
            }
            tail = cur;
            tail->left = nullptr;
            stk.pop();
            cur = cur->right;
        }
    }
    tail->right = nullptr;

    return head;
}
