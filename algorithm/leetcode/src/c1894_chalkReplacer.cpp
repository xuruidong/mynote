#include "c1894_chalkReplacer.h"

c1894_chalkReplacer::c1894_chalkReplacer()
{
    //ctor
}

c1894_chalkReplacer::~c1894_chalkReplacer()
{
    //dtor
}

int chalkReplacer(vector<int>& chalk, int k)
{
    vector<long long> tmp(chalk.size(), 0);
    tmp[0] = chalk[0];
    for(int i=1; i<chalk.size(); ++i) {
        tmp[i] += tmp[i-1] + chalk[i];
    }
    k %= tmp[chalk.size()-1];
    auto it = upper_bound(tmp.begin(), tmp.end(), k);
    return it - tmp.begin();
}
