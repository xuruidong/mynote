#include "c12_intToRoman.h"

c12_intToRoman::c12_intToRoman()
{
    //ctor
}

c12_intToRoman::~c12_intToRoman()
{
    //dtor
}

string intToRoman(int num)
{
    vector<vector<string>> i2r = {
        {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
        {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
        {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
        {"", "M", "MM", "MMM"}
    };
    string ans = "";
    string ns = to_string(num);
    for(int i=0; i<ns.size(); ++i) {
        ans += i2r[ns.size()-1-i][ns[i]-'0'];
    }

    return ans;
}
