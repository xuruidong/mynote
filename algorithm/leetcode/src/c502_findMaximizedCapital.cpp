#include "c502_findMaximizedCapital.h"

c502_findMaximizedCapital::c502_findMaximizedCapital()
{
    //ctor
}

c502_findMaximizedCapital::~c502_findMaximizedCapital()
{
    //dtor
}

int c502_findMaximizedCapital::findMaximizedCapital(int k, int w, vector<int> &profits, vector<int>& capital)
{
    vector<pair<int, int>> cap;
    for (int i=0; i<profits.size(); ++i) {
        cap.emplace_back(capital[i], profits[i]);
    }
    sort(cap.begin(), cap.end());

    priority_queue<int> q;

    int i = 0;
    while(k) {
        for(; i<cap.size(); ++i) {
            if (cap[i].first <= w) {
                q.push(cap[i].second);
            }
            else {
                break;
            }
        }
        if(q.size() < 1) {  // emm....
            break;
        }
        w += q.top();
        q.pop();
        --k;
    }
    return w;
}

void c502_findMaximizedCapital::test()
{
    int k=3;
    int w = 0;
    vector<int> profits = {1,2,3};
    vector<int> capital = {0,1,2};
    int ans = 0;

    cout<<"c502_findMaximizedCapital start"<<endl;
    ans = findMaximizedCapital(k, w, profits, capital);

    cout<<"res = "<<ans<<endl;
    cout<<"c502_findMaximizedCapital end"<<endl;
}
