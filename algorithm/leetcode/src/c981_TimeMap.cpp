#include "c981_TimeMap.h"

c981_TimeMap::c981_TimeMap()
{
    //ctor
}

c981_TimeMap::~c981_TimeMap()
{
    //dtor
}



void c981_TimeMap::set(string key, string value, int timestamp)
{
    auto &lst = umap[key];
    c981_stru tmp;
    tmp.timestamp = timestamp;
    tmp.value = value;
    /*
    auto lst_it = upper_bound(lst.begin(), lst.end(), tmp, [](const c981_stru &s1, const c981_stru &s2)->bool {
                                return s1.timestamp < s2.timestamp;
                              });

    lst.insert(lst_it, tmp);
    */
    lst.push_back(tmp);
}

string c981_TimeMap::get(string key, int timestamp)
{
    auto &lst = umap[key];
    c981_stru tmp;
    tmp.timestamp = timestamp;
    tmp.value = "";
    auto lst_it = upper_bound(lst.begin(), lst.end(), tmp, [](const c981_stru &s1, const c981_stru &s2)->bool {
                                return s1.timestamp < s2.timestamp;
                              });
    if(lst_it == lst.begin()) {
        return "";
    }

    return (--lst_it)->value;
}

void c981_TimeMap::test()
{
#if 0
    c981_stru tmp;
    tmp.timestamp = 1;
    tmp.value = "bar";
    list<struct c981_stru> lst;
    lst.insert(lst.begin(), tmp);

    tmp.timestamp = 2;
    lst.insert(lst.begin(), tmp);
    tmp.timestamp = 3;
    lst.insert(lst.begin(), tmp);

    cout<<lst.size()<<endl;
    return;
#endif // 0

    set("foo", "bar", 1);

    cout<<"~~~"<<get("foo", 1)<<endl;
    cout<<"~~~"<<get("foo", 3)<<endl;

    set("foo", "bar2", 4);
    cout<<"~~~"<<get("foo", 4)<<endl;
    cout<<"~~~"<<get("foo", 5)<<endl;
    cout<<"c981_TimeMap test end"<<endl;
}
