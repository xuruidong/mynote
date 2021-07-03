#include "c451_frequencySort.h"

c451_frequencySort::c451_frequencySort()
{
    //ctor
}

c451_frequencySort::~c451_frequencySort()
{
    //dtor
}

struct f_stract {
    char c;
    int n;

    f_stract() {
        c = 0;
        n = 0;
    }
};

string frequencySort(string s)
{
    vector<f_stract> data(128);
    for(int i=0; i<data.size(); ++i) {
        data[i].c = i;
        data[i].n = 0;
    }

    for(char c:s) {
        ++data[c].n;
    }

    sort(data.begin(), data.end(), [](f_stract &s1, f_stract &s2)->bool{
            if(s1.n < s2.n) {
                return true;
            } else if(s1.n == s2.n) {
                if(s1.c - s2.c == 32){
                    return false;
                } else if(s1.c - s2.c == -32) {
                    return true;
                }
            }
            return false;
         });

    string ans;
    for(int i=0; i<data.size(); ++i) {
        string tmp(data[i].n, data[i].c);
        ans += tmp;
    }
    return ans;
}
