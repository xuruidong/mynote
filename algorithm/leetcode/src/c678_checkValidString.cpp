#include "c678_checkValidString.h"

c678_checkValidString::c678_checkValidString()
{
    //ctor
}

c678_checkValidString::~c678_checkValidString()
{
    //dtor
}

bool checkValidString(string s)
{
    //xxxxxxx
    //stack<char> stk;
    int left = 0;
    int n = 0;
    for(char c:s) {
        if(c == '(') {
            //stk.push('(');
            ++left;
        }
        else if(c == '*') {
            ++n;
        }
        else {
            if(left) {
                --left;
            }
            else if(n) {
                --n;
            }
            else {
                return false;
            }
        }
    }
    if(left) {
        return false;
    }
    return true;
}
