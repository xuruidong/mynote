#include "Solution.h"

void recu(std::string s, int left, int right, int n,std::vector<std::string> &res)
{
    if(left<n){
        recu(s+'(', left+1, right, n, res);
    }
    if(right < left){
        recu(s+')', left, right+1, n, res);
    }
    if(right == n){
        res.push_back(s);
    }
}

std::vector<std::string> Solution::c22_generateParenthsis(int n)
{
    std::vector<std::string> res;
    recu("(", 1, 0, n, res);
    return res;
}
