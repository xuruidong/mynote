#include "c13_romanToInt.h"

c13_romanToInt::c13_romanToInt()
{
    //ctor
}

c13_romanToInt::~c13_romanToInt()
{
    //dtor
}

int romanToInt(string s)
{
    int ans = 0;
    for(int i=0; i<s.size(); ++i) {
        if(s[i] == 'M') {
            ans += 1000;
        } else if(s[i] == 'D') {
            ans += 500;
        } else if(s[i] == 'C') {
            if(i+1 < s.size()){
                if(s[i+1] == 'M') {
                    ans += 900;
                    ++i;
                } else if(s[i+1] == 'D') {
                    ans += 400;
                    ++i;
                } else {
                    ans +=100;
                }
            } else {
                ans += 100;
            }
        } else if(s[i] == 'L') {
            ans += 50;
        } else if(s[i] == 'X') {
            if(i+1 < s.size()){
                if(s[i+1] == 'C') {
                    ans += 90;
                    ++i;
                } else if(s[i+1] == 'L') {
                    ans += 40;
                    ++i;
                } else {
                    ans +=10;
                }
            } else {
                ans += 10;
            }
        } else if(s[i] == 'V') {
            ans += 5;
        } else if(s[i] == 'I') {
            if(i+1 < s.size()){
                if(s[i+1] == 'X') {
                    ans += 9;
                    ++i;
                } else if(s[i+1] == 'V') {
                    ans += 4;
                    ++i;
                } else {
                    ans +=1;
                }
            } else {
                ans += 1;
            }
        }
    }
    return ans;
}

int romanToInt2(string s)
{
    char last = '0';
    int ans = 0;
    for(int i=0; i<s.size(); ++i) {
        if(s[i] == 'M') {
            if(last == 'C')
                ans += 800;
            else
                ans += 1000;
        } else if(s[i] == 'D') {
            if(last == 'C')
                ans += 300;
            else
                ans += 500;
        } else if(s[i] == 'C') {
            if(last == 'X')
                ans += 80;
            else
                ans += 100;
        } else if(s[i] == 'L') {
            if(last == 'X')
                ans += 30;
            else
                ans += 50;
        } else if(s[i] == 'X') {
            if(last == 'I')
                ans += 8;
            else
                ans += 10;
        } else if(s[i] == 'V') {
            if(last == 'I')
                ans += 3;
            else
                ans += 5;
        } else if(s[i] == 'I') {
            ans += 1;
        }

        last = s[i];
    }
    return ans;
}
