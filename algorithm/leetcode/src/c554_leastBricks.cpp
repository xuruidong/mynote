#include "c554_leastBricks.h"

c554_leastBricks::c554_leastBricks()
{
    //ctor
}

c554_leastBricks::~c554_leastBricks()
{
    //dtor
}

// [[100000000],[100000000],[100000000]]    3

/*
 timeout   87 / 87 个通过测试用例
状态：超出时间限制
*/

int leastBricks(vector<vector<int>>& wall) {
        int len = wall.size();
        //int sum = accumulate(wall[0].begin(), wall[0].end(), 0);

        vector<unordered_set<int>> sumset(len);
        set<int> allsum;
        for(int i=0; i<len; ++i) {
            int tmp = 0;
            for(int j=0; j<wall[i].size()-1; ++j) {
                tmp += wall[i][j];
                sumset[i].insert(tmp);
                allsum.insert(tmp);
            }
        }

        int least =  len;
        for(auto it: allsum) {
        //for(int i=1; i<sum; ++i) {
            int tmp = 0;
            for(int j=0; j<len; ++j) {
                if(sumset[j].find(it) == sumset[j].end()) {
                    ++tmp;
                }
            }
            least = least<tmp?least:tmp;
        }
        return least;
    }


int c554_leastBricks::leastBricks(vector<vector<int>>& wall) {
    int len = wall.size();

    //vector<unordered_set<int>> sumset(len);
    map<int, int> allsum;
    int most =  0;
    for(int i=0; i<len; ++i) {
        int tmp = 0;
        for(int j=0; j<wall[i].size()-1; ++j) {
            tmp += wall[i][j];
            //sumset[i].insert(tmp);
            ++allsum[tmp];
            most = most>allsum[tmp]?most:allsum[tmp];
        }
    }
    return len-most;
}

void c554_leastBricks::test()
{
    vector<vector<int>> wall = {{100000000}, {100000000}, {100000000}};
    cout<<leastBricks(wall)<<endl;
}
