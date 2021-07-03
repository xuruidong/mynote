#include "c474_findMaxForm.h"

c474_findMaxForm::c474_findMaxForm()
{
    //ctor
}

c474_findMaxForm::~c474_findMaxForm()
{
    //dtor
}

static int process(vector<string> &strs, int index, int m, int n, int zero_len, int one_len, int ans, unordered_map<int, int> &umap)
{
    int zl=0, ol=0;

    if(zero_len > m) {
        return -1;
    }
    if(one_len > n) {
        return -1;
    }
    if(index >= strs.size()) {
        return ans;
    }

    for(int i=0; i<strs[index].size(); ++i){
        if(strs[index][i] == '0') {
            ++zl;
        } else {
            ++ol;
        }
    }

    auto it = umap.find(index+1);
    if(it != umap.end()) {
        return it->second;
    }
    int val = max(process(strs, index+1, m, n, zero_len+zl, one_len+ol, ans+1, umap), process(strs, index+1, m, n, zero_len, one_len, ans, umap));
    umap[index+1] = val;
    return val;
}

int findMaxForm(vector<string>& strs, int m, int n) {
    unordered_map<int, int> umap;
    return process(strs, 0, m, n, 0, 0, 0, umap);
}
