#include "c429_levelOrder.h"

c429_levelOrder::c429_levelOrder()
{
    //ctor
}

c429_levelOrder::~c429_levelOrder()
{
    //dtor
}

vector<vector<int>> c429_levelOrder::levelOrder(Node* root)
{
    queue<Node *> q1, q2;
    queue<Node *> &curr_q = q1;
    queue<Node *> &next_q = q2;
    //queue<Node *> &tmp_q = q1;
    vector<vector<int>> ans;
    if(!root) {
        return {{}};
    }
    curr_q.push(root);
    vector<int> v;
    while(!curr_q.empty()) {
        Node *n = curr_q.front();
        curr_q.pop();
        v.push_back(n->val);
        for(int i=0; i<n->children.size(); ++i) {
            next_q.push(n->children[i]);
        }
        if(curr_q.empty()) {
            ans.push_back(v);
            v.clear();
            curr_q.swap(next_q);
            /*
            tmp_q = curr_q;
            curr_q = next_q;
            next_q = tmp_q;
            */
        }
    }
    return ans;
}
