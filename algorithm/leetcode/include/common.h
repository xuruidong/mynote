#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>

#include <algorithm>
#include <numeric>

#include <math.h>
#include <string.h>

#include "limits.h"
#include "utils.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif // COMMON_H_INCLUDED
