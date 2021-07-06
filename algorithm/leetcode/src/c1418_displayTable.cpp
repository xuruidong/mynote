#include "c1418_displayTable.h"

c1418_displayTable::c1418_displayTable()
{
    //ctor
}

c1418_displayTable::~c1418_displayTable()
{
    //dtor
}

vector<vector<string>> displayTable(vector<vector<string>>& orders)
{
    set<string> food_set;
    set<int> table_set;
    unordered_map<string, unordered_map<string, int>> table_food_map;
    for(int i=0; i<orders.size(); ++i) {
        table_set.insert(stoi(orders[i][1]));
        food_set.insert(orders[i][2]);
        table_food_map[orders[i][1]][orders[i][2]] += 1;
    }

    vector<vector<string>> ans;
    vector<string> tmp;
    tmp.emplace_back("Table");
    for (auto it=food_set.begin(); it != food_set.end(); ++it) {
        tmp.emplace_back(*it);
    }
    ans.push_back(tmp);
    tmp.clear();

    for(auto it=table_set.begin(); it != table_set.end(); ++it) {
        string table_str = to_string(*it);
        tmp.emplace_back(table_str);
        for(auto food_it = food_set.begin(); food_it != food_set.end(); ++food_it) {
            tmp.emplace_back(to_string(table_food_map[table_str][*food_it]));
        }
        ans.push_back(tmp);
        tmp.clear();
    }
    return ans;
}

void c1418_displayTable::test()
{
    set<string> s;
    s.insert("Ceviche");
    s.insert("Beef Burrito");
    s.insert("Fried Chicken");
    s.insert("Water");
    s.insert("Canadian Waffles");
    s.insert("Canb");
    s.insert("1");
    s.insert("12");
    s.insert("2");

    for(auto it=s.begin(); it != s.end(); ++it) {
        cout<<*it<<endl;
    }
}
