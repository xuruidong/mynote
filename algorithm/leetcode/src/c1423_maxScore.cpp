#include "c1423_maxScore.h"

c1423_maxScore::c1423_maxScore()
{
    //ctor
}

c1423_maxScore::~c1423_maxScore()
{
    //dtor
}

int c1423_maxScore::maxScore(vector<int>& cardPoints, int k)
{
    int win_size = cardPoints.size()-k;
    int sum = accumulate(cardPoints.begin(), cardPoints.begin()+win_size, 0);

    int min_sum = sum;
    int all = sum;

    for(int i=win_size; i<cardPoints.size(); ++i) {
        sum += cardPoints[i] - cardPoints[i-win_size];
        min_sum = min_sum<sum?min_sum:sum;
        all += cardPoints[i];
    }
    return all-min_sum;
}

void c1423_maxScore::test()
{
    cout<<"c1423 test start..."<<endl;
    vector<int> nums = {1,79,80,1,1,1,200,1};
    cout<<maxScore(nums, 3)<<endl;
    cout<<"c1423 test end"<<endl;
}
