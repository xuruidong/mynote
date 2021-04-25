#include "c91_numDecodings.h"

c91_numDecodings::c91_numDecodings()
{
    //ctor
}

c91_numDecodings::~c91_numDecodings()
{
    //dtor
}

static void process(string &s1, int index, int &sum)
{
    if(s1[index] == '0'){
        return;
    }
    if(index >= s1.size()-1){
        ++sum;
        return;
    }

    if(s1[index] == '1'){
        process(s1, index+2, sum);
    } else if(s1[index] == '2' && s1[index+1] <= '6' && s1[index+1] >= '0') {
        process(s1, index+2, sum);
    }
    process(s1, index+1, sum);
}

int c91_numDecodings::numDecodings(string s)
{
    int sum = 0;
    process(s, 0, sum);
    return sum;
}

int c91_numDecodings::numDecodings2(string s)
{
    int sum = 1;

    return sum;
}
