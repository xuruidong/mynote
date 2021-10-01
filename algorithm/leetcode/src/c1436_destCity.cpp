#include "c1436_destCity.h"

c1436_destCity::c1436_destCity()
{
    //ctor
}

c1436_destCity::~c1436_destCity()
{
    //dtor
}

string c1436_destCity::destCity(vector<vector<string>>& paths)
{
    unordered_map<string, string> umap;
    for(int i=0; i<paths.size(); ++i) {
        auto it = umap.find(paths[i][1]);
        if (it != umap.end()) {
            umap[paths[i][0]] = it->second;
            umap.erase(it);
        }
        else {
            umap[paths[i][0]] = paths[i][1];
        }
    }
    cout<<umap.size()<<endl;
    for(auto it = umap.begin(); it != umap.end(); ++it) {
        auto it2 = umap.find(it->second);
        if (it2 == umap.end()) {
            return it->second;
        }
        cout<<it->first<<"---"<<it->second<<endl;
    }
    return "";
}

void c1436_destCity::test()
{
    vector<vector<string>> paths = {{"London","New York"},{"New York","Lima"},{"Lima","Sao Paulo"}};
    cout<<destCity(paths)<<endl;
}
