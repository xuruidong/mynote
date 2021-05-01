#include "c39_combinationSum.h"

/*
 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1：

输入：candidates = [2,3,6,7], target = 7,
所求解集为：
[
  [7],
  [2,2,3]
]
示例 2：

输入：candidates = [2,3,5], target = 8,
所求解集为：
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
 

提示：

1 <= candidates.length <= 30
1 <= candidates[i] <= 200
candidate 中的每个元素都是独一无二的。
1 <= target <= 500

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

c39_combinationSum::c39_combinationSum()
{
    //ctor
}

c39_combinationSum::~c39_combinationSum()
{
    //dtor
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int>> ans;
    int len = candidates.size();
    int dp[len][target+1];
    int n=candidates[0];
    int tmp = 0;
    memset(dp, 0, len*(target+1));
    while(tmp<=target) {
        dp[0][tmp] = 1;
        tmp += n;
    }

    if(dp[0][target] == 1) {
        vector<int> sub_ans(target/candidates[0], candidates[0]);
        ans.push_back(sub_ans);
    }

    for(int i=1; i<len; ++i) {
        dp[i][0] = 1;
        for(int j=1; j<=target; ++j) {
            tmp = 0;
            int sum = 0;
            while(j>=tmp) {
                sum += dp[i-1][j-tmp];
                tmp += candidates[i];
            }
            dp[i][j] = sum;
        }
        /*
        if(dp[i][target] != dp[i-1][target]) {
            // ???
        }
        */
    }

}

static void recur(vector<int>& candidates, int index, int target, vector<int> anstmp, vector<vector<int>> &ans)
{
    if(target == 0) {
        ans.push_back(anstmp);
        return;
    }

    if(index >= candidates.size()) {
        return;
    }
    /*
    if(target == candidates[index]) {
        anstmp.push_back(candidates[index]);
        ans.push_back(anstmp);
        return;
    }
    */

    int tmp = 0;
    while(target >= tmp){
        recur(candidates, index+1, target-tmp, anstmp, ans);
        tmp += candidates[index];
        anstmp.push_back(candidates[index]);
    }
}

vector<vector<int>> c39_combinationSum::combinationSum2(vector<int>& candidates, int target)
{
    vector<int> anstmp;
    vector<vector<int>> ans;
    recur(candidates, 0, target, anstmp, ans);
    return ans;
}


static void recur3(vector<int>& candidates, int index, int target, vector<int> &anstmp, vector<vector<int>> &ans)
{
    if(target == 0) {
        ans.push_back(anstmp);
        return;
    }

    if(index >= candidates.size()) {
        return;
    }

    int tmp = 0;
    while(target >= tmp){
        recur(candidates, index+1, target-tmp, anstmp, ans);
        tmp += candidates[index];
        anstmp.push_back(candidates[index]);
    }

    tmp = 0;
    while(target >= tmp){
        tmp += candidates[index];
        anstmp.pop_back();
    }
}

vector<vector<int>> c39_combinationSum::combinationSum3(vector<int>& candidates, int target)
{
    vector<int> anstmp;
    vector<vector<int>> ans;
    recur(candidates, 0, target, anstmp, ans);
    return ans;
}

void c39_combinationSum::test()
{
    /*
     * {1}, 2 --> 1,1
     *
     */
    vector<int> candidates = {2,3,6,7};
    vector<vector<int>> ret = combinationSum2(candidates, 7);
    for(auto &v : ret) {
        utils::vector_print(v);
    }
}
