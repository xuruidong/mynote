#include "c56_merge.h"

c56_merge::c56_merge()
{
    //ctor
}

c56_merge::~c56_merge()
{
    //dtor
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end(), [](vector<int> &v1, vector<int> &v2){
            if(v1[0] < v2[0]) {
                return true;
            } else if(v1[0] == v2[0]) {
                return v1[1] < v2[1];
            }
            return false;
         });

    vector<int> tmp;
    tmp.push_back(intervals[0][0]);
    int pre = intervals[0][1];
    for(int i=1; i<intervals.size(); ++i) {
        if(intervals[i][0] > pre) {
            tmp.push_back(pre);
            ans.push_back(tmp);
            tmp.clear();
            tmp.push_back(intervals[i][0]);
        }
        pre = pre>intervals[i][1]?pre:intervals[i][1];
    }
    tmp.push_back(pre);
    ans.push_back(tmp);
    return ans;
}
