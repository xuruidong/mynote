#include "c121_maxProfit.h"

c121_maxProfit::c121_maxProfit()
{
    //ctor
}

c121_maxProfit::~c121_maxProfit()
{
    //dtor
}

int c121_maxProfit::maxProfit(vector<int>& prices)
{
    int min_price = INT_MAX;
    int max_profit = 0;
    for(auto &p:prices){
        min_price = min_price<p?min_price:p;
        max_profit = p-min_price > max_profit?p-min_price:max_profit;
    }
    return max_profit;
}
