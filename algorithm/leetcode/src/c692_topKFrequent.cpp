#include "c692_topKFrequent.h"

c692_topKFrequent::c692_topKFrequent()
{
    //ctor
}

c692_topKFrequent::~c692_topKFrequent()
{
    //dtor
}

vector<string> c692_topKFrequent::topKFrequent(vector<string>& words, int k)
{
    unordered_map<string, int> umap;
    auto cmp = [](const pair<string, int> &p1, const pair<string, int> &p2)->bool{
                if(p1.second > p2.second){
                    return true;
                } else if(p1.second == p2.second) {
                    return p1.first < p2.first;
                }
                return false;
            };

    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> q(cmp);

    for(string &w:words) {
        ++umap[w];
    }

    for(auto &it: umap) {
        cout<<it.first<<"   "<<it.second<<endl;
        if(q.size() < k) {
            q.push(it);
        } else {
            q.push(it);
            q.pop();
        }
    }

    k = q.size()>k?k:q.size();
    vector<string> ans(k);
    for(int i=k-1; i>=0; --i) {
        ans[i] = q.top().first;
        q.pop();
    }
    return ans;
}

class student{
    public:
        int age;
        string name;
        /**重载小于操作符，
	      *这里必须是非成员函数才可以
		*/
		/*
        friend bool operator<(const student& a, const student & b){
            return a.age < b.age;
        }
        */

        student(string name, int age) {
            this->name = name;
            this->age = age;
        }
};

struct mycmp{
    bool operator()(const student & a,const student & b){
        return a.age < b.age;
    }
};

bool cmpfunc(const student& a, const student& b){
    return a.age > b.age;
}


#include <functional>
void p_test()
{
    function<bool(const student&,const student &)> func(cmpfunc);

    std::priority_queue<student, vector<student>, function<bool(const student&,const student&)>> q(func);
    q.emplace("aaa", 12);
    q.emplace("bbb", 100);
    q.emplace("ccc", 27);
    q.emplace("ddd", 2);
    q.emplace("eee", 93);
    while(!q.empty()) {
        cout<<q.top().name<<" "<<q.top().age<<" ";
        q.pop();
    }
    cout<<endl;
}

void c692_topKFrequent::test()
{
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    vector<string> ans = topKFrequent(words, 2);
    for(auto &s: ans) {
        cout<<s<<"  ";
    }
    cout<<endl;

    std::priority_queue<int, vector<int>> q;
    q.push(100);
    q.push(102);
    q.push(34);
    q.push(200);
    while(!q.empty()) {
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;

    p_test();
}
