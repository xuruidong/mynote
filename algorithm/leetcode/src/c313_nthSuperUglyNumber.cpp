#include "c313_nthSuperUglyNumber.h"

c313_nthSuperUglyNumber::c313_nthSuperUglyNumber()
{
    //ctor
}

c313_nthSuperUglyNumber::~c313_nthSuperUglyNumber()
{
    //dtor
}

int c313_nthSuperUglyNumber::nthSuperUglyNumber(int n, vector<int>& primes)
{
    priority_queue<long long, vector<long long>, greater<long long>> q;
    unordered_set<long long> uset;
    q.push(1);
    int ans_num = 0;
    long long ans = 1;
    while(ans_num < n) {
        ans = q.top();
        for(int &p:primes) {
            long long v = ans * p;

            if(uset.find(v) != uset.end()) {
                continue;
            }
            uset.insert(v);
            q.push(v);
        }
        ++ans_num;
        q.pop();
    }
    return ans;
}

void c313_nthSuperUglyNumber::test()
{
    vector<int> primes = {2,7,13,19};
    int n = 22;
    int ret = nthSuperUglyNumber(n, primes);
    cout<< "nthSuperUglyNumber ans = "<<ret<<endl;
    cout<< "c313_nthSuperUglyNumber test end"<<endl;
}
