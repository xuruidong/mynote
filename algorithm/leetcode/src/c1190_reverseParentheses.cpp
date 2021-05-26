#include "c1190_reverseParentheses.h"

c1190_reverseParentheses::c1190_reverseParentheses()
{
    //ctor
}

c1190_reverseParentheses::~c1190_reverseParentheses()
{
    //dtor
}


static int recur(string &s, int start, stack<char> &stk)
{
    //stack<char> stk;
    for(int i=start; i<s.size(); ++i) {
        if(s[i] == '(') {
            stack<char> stk2;
            i = recur(s, i+1, stk2);
            while(!stk2.empty()) {
                stk.push(stk2.top());
                stk2.pop();
            }
        } else if(s[i] == ')') {
            return i;
        } else {
            stk.push(s[i]);
        }
    }
    return s.size()-1;
}
string reverseParentheses(string s)
{
    stack<char> stk;
    string ans;
    int i=0;
    while(i<s.size()){
        while(i<s.size() && s[i] != '(') {
            ans += s[i];
            ++i;
        }
        i = recur(s, i+1, stk);
        while(!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        ++i;
    }
    return ans;
}
