#include "c589_preorder.h"

c589_preorder::c589_preorder()
{
    //ctor
}

c589_preorder::~c589_preorder()
{
    //dtor
}

static void recur(Node *root, vector<int> &ans)
{
    if(!root) {
        return;
    }
    ans.push_back(root->val);
    for(int i=0; i<root->children.size(); ++i) {
        recur(root->children[i], ans);
    }
}

vector<int> preorder(Node* root) {
    vector<int> ans;
    recur(root, ans);
    return ans;
}
