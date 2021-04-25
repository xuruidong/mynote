#include "c87_isScramble.h"

#include "common.h"

c87_isScramble::c87_isScramble()
{
    //ctor
}

c87_isScramble::~c87_isScramble()
{
    //dtor
}

static bool process(string s1, int start, int endi, string target)
{
    /*
    int len = endi-start+1;
    if(len <= 1){
        return false;
    }

    for(int i=1; i<endi; ++i){
        string s2_1(s1, 0, i);
        string s2_2(s1, i+1, len-1);
        string s2 = s2_2 + s2_1;
        if(process(s2, start, i, target) || process(s2, i+1, endi, target)){
            return true;
        }
        if()
    }
    */
}

bool c87_isScramble::isScramble(string s1, string s2)
{

}
