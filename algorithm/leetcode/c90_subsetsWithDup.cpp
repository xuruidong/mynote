class Solution {
    vector<vector<int>> rec(vector<int>& nums, int ind) {
        if(ind >= nums.size()){
            return {{}};
        }
        vector<vector<int>> res = rec(nums, ind+1);
        vector<vector<int>> ret;
        unordered_set <vector<int>> s;
        for(auto it=res.begin();it!=res.end(); ++it){
            ret.push_back(*it);
            *it.push_back(nums[ind]);
            auto sit = s.find(*it);
            if(sit != s.end()){
                continue;
            }
            ret.push_back(*it);
        }
        return ret;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        return rec(nums, 0);
    }
};
