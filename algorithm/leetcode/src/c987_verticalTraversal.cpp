#include "c987_verticalTraversal.h"

c987_verticalTraversal::c987_verticalTraversal()
{
    //ctor
}

c987_verticalTraversal::~c987_verticalTraversal()
{
    //dtor
}
#if 0
static void dfs(TreeNode* root, int col, int row/*depth*/, map<pair<int, int>, vector<int>> &mp)
{
    if(root == nullptr) {
        return;
    }
    mp[{col, row}].emplace_back(root->val);
    dfs(root->left, col-1, row+1, mp);
    dfs(root->right, col+1, row+1, mp);
}
vector<vector<int>> verticalTraversal(TreeNode* root)
{
    vector<vector<int>> ans;
    map<pair<int, int>, vector<int>> mp;
    dfs(root, 0, 0, mp);
    int prev_col = INT_MIN;
    vector<int> tmp;
    for(auto &it = mp.begin(); it != mp.end(); ++it) {
        if(it.first.first != prev_col) {
            if(!tmp.empty()) {
                ans.emplace_back(tmp);
            }
            tmp.clear();
            tmp.emplace_back(it.second);
            prev_col = it.first.first;
        }
        else {
            tmp.emplace_back(it.second);
        }
    }
    if(!tmp.empty()) {
        ans.emplace_back(tmp);
    }
    return ans;
}

#else
static void dfs(TreeNode* root, int col, int row/*depth*/, vector<vector<int>> &vec)
{
    if(root == nullptr) {
        return;
    }
    vector<int> tmp = {col, row, root->val};
    vec.emplace_back(tmp);
    dfs(root->left, col-1, row+1, mp);
    dfs(root->right, col+1, row+1, mp);
}
vector<vector<int>> verticalTraversal(TreeNode* root)
{
    vector<vector<int>> ans;
    vector<vector<int>> mp;
    dfs(root, 0, 0, mp);
    sort(mp.begin(), mp.end());

    int prev_col = INT_MIN;
    vector<int> tmp;
    for(auto &v : mp) {
        if(v[0] != prev_col) {
            if(!tmp.empty()) {
                ans.emplace_back(tmp);
            }
            tmp.clear();
            tmp.emplace_back(v[2]);
            prev_col = v[0];
        }
        else {
            tmp.emplace_back(v[2]);
        }
    }
    if(!tmp.empty()) {
        ans.emplace_back(tmp);
    }
    return ans;
}
#endif
