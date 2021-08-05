#include "c802_eventualSafeNodes.h"

c802_eventualSafeNodes::c802_eventualSafeNodes()
{
    //ctor
}

c802_eventualSafeNodes::~c802_eventualSafeNodes()
{
    //dtor
}

#define RES_TRUE 1
#define RES_FALSE -1
#define RES_UNDEF 0

static bool dfs(vector<vector<int>>& graph, int ind, int *s, int *res_map)
{
    if(ind >= graph.size()) {
        return true;
    }
    if(res_map[ind] == RES_FALSE) {
        return false;
    } else if(res_map[ind] == RES_TRUE) {
        return true;
    }
    for(int i=0; i<graph[ind].size(); ++i) {
        if(res_map[graph[ind][i]] == RES_FALSE) {
            return false;
        }
        if(s[graph[ind][i]] == 1) {
            //cout<<"1###"<<ind<<"  "<<i<<endl;
            return false;
        }
        s[graph[ind][i]] = 1;
        if (dfs(graph, graph[ind][i], s, res_map) == false) {
            //cout<<"###"<<ind<<"  "<<i<<endl;
            res_map[graph[ind][i]] = RES_FALSE;
            return false;
        }
        else {
            res_map[graph[ind][i]] = RES_TRUE;
        }
        s[graph[ind][i]] = 0;
    }
    return true;
}

vector<int> c802_eventualSafeNodes::eventualSafeNodes(vector<vector<int>>& graph)
{
#define MAX_NODES 10001
    int res_map[MAX_NODES] = {0};
    int steps[MAX_NODES] = {0};
    vector<int> ans;
    for(int i=0; i<graph.size(); ++i) {
        memset(steps, 0, sizeof(steps));
        if(dfs(graph, i, steps, res_map) == true) {
            res_map[i] = RES_TRUE;
            ans.emplace_back(i);
        }
        else {
            res_map[i] = RES_FALSE;
        }
    }
    return ans;
}

void c802_eventualSafeNodes::test()
{
    vector<vector<int>> graph = {{},{0,2,3,4},{3},{4},{}};
    vector<int> ans = eventualSafeNodes(graph);

    utils::vector_print(ans);
    cout<<"c802_eventualSafeNodes test end\n"<<endl;
}
