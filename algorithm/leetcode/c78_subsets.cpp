class Solution {
    vector<vector<int>> process(vector<int>& nums, int ind) {
        if(ind >= nums.size()){
            return {{}};
        }
        vector<vector<int>> res = process(nums, ind+1);
        vector<vector<int>> ret;
        for(auto it = res.begin(); it != res.end(); ++it){
            ret.push_back(*it);
            *it.push_back(nums[ind]);
        }
        return ret;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        return process(nums, 0);
    }
};

class Solution2 {
    vector<vector<int>> process(vector<int>& nums, int ind, int needed) {
        if(ind >= nums.size()){
            return {{}};
        }
        vector<vector<int>> res = process(nums, ind+1);
        vector<vector<int>> ret;
        for(auto it = res.begin(); it != res.end(); ++it){
            ret.push_back(*it);
            *it.push_back(nums[ind]);
        }
        return ret;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<vector<int>> ret2;
        vector<int> tmp;

        for(int i=0; i<nums.size(); ++i){
            for(auto it=ret.begin(); it!=ret.end(); ++it){

            }
        }
        return ret;
    }
};
