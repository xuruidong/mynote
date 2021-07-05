#include "c726_countOfAtoms.h"

c726_countOfAtoms::c726_countOfAtoms()
{
    //ctor
}

c726_countOfAtoms::~c726_countOfAtoms()
{
    //dtor
}

#define STATE_LEFT_BRACKET  0
#define STATE_RIGHT_BRACKET 1
#define STATE_UPPERCASE     2
#define STATE_LOWERCASE     3
#define STATE_DIGIT         4

static unordered_map<string, int> fsm(string &s, int &index)
{
    cout<<"in fsm:"<<&s<<endl;
    unordered_map<string, int> umap;
    if(index >= s.size()) {
        return umap;
    }
    string tmp = "";
    string digit_str = "";
    int state = STATE_LEFT_BRACKET;
    int right_bracket_flag = false;
    for(int i=index; i<s.size(); ++i) {
        if(s[i] == '(') {
            state = STATE_LEFT_BRACKET;
            if(digit_str != "") {
                //cout<<"2 digit str:"<<digit_str<<endl;
                int v = stoi(digit_str);
                umap[tmp] += v;
            }
            else {
                umap[tmp] += 1;
            }
            ++i;
            unordered_map<string, int> umap2 = fsm(s, i);
            for(auto it=umap2.begin(); it != umap2.end(); ++it) {
                umap[it->first] += it->second;
                //cout<<"~~~~"<<umap[it->first]<<endl;
            }
            continue;
        }

        switch(state){
            case STATE_LEFT_BRACKET:
                if(s[i] >= 'A' && s[i] <='Z') {
                    tmp = s[i];
                    state = STATE_UPPERCASE;
                }
                else if(s[i] >= 'a' && s[i] <='z') {

                }
                else if(s[i] >= '0' && s[i] <='9') {

                }
            break;
            case STATE_UPPERCASE:
                if(s[i] >= 'a' && s[i] <='z') {
                    tmp += s[i];
                    state = STATE_LOWERCASE;
                }
                else if(s[i] >= '0' && s[i] <='9') {
                    digit_str = s[i];
                    state = STATE_DIGIT;
                }
                else if(s[i] == ')') {
                    umap[tmp] += 1;
                    tmp = "";
                    state = STATE_RIGHT_BRACKET;
                }
            break;
            case STATE_LOWERCASE:
                if(s[i] >= '0' && s[i] <='9') {
                    digit_str = s[i];
                    state = STATE_DIGIT;
                }
                else if(s[i] >= 'A' && s[i] <='Z') {
                    umap[tmp] += 1;
                    tmp = s[i];
                    state = STATE_UPPERCASE;
                }
                else if(s[i] == ')') {
                    umap[tmp] += 1;
                    tmp = "";
                    state = STATE_RIGHT_BRACKET;
                }
            case STATE_DIGIT:
                if(s[i] >= '0' && s[i] <='9') {
                    digit_str += s[i];
                }
                else if(s[i] >= 'A' && s[i] <='Z') {
                    cout<<"digit str:"<<digit_str<<endl;
                    int v = stoi(digit_str);
                    digit_str = "";
                    if(right_bracket_flag) {
                        for(auto it=umap.begin(); it != umap.end(); ++it) {
                            it->second *= v;
                        }
                        --i;
                        return umap;
                    }

                    umap[tmp] += v;
                    tmp = s[i];
                    state = STATE_UPPERCASE;
                }
                else if(s[i] == ')') {
                    int v = stoi(digit_str);
                    umap[tmp] += v;
                    digit_str = "";
                    tmp = "";
                }
                break;
            case STATE_RIGHT_BRACKET:
                if(s[i] >= '0' && s[i] <='9') {
                    digit_str = s[i];
                    state = STATE_DIGIT;
                }
                else {
                    --i;
                    return umap;
                }
                right_bracket_flag = true;
                break;
        }
    }
    if(digit_str != "") {
        cout<<"2 digit str:"<<digit_str<<endl;
        int v = stoi(digit_str);
        umap[tmp] += v;
    }
    else {
        umap[tmp] += 1;
    }

    return umap;
}

struct data_s {
    string s;
    int n;

    data_s(string s1, int n1) {
        s = s1;
        n = n1;
    }
};

string c726_countOfAtoms::countOfAtoms(string formula)
{
    int index = 0;
    unordered_map<string, int> umap = fsm(formula, index);
    vector<data_s> v;
    cout<<"umap size:"<<umap.size()<<endl;
    for(auto it=umap.begin(); it != umap.end(); ++it) {
        v.emplace_back(it->first, it->second);
    }
    sort(v.begin(), v.end(), [](data_s &s1, data_s &s2)->bool {
            return s1.s < s2.s;
         });
    string ans;
    for (auto &data:v) {
        ans += data.s;
        if(data.n > 1)
            ans += to_string(data.n);
    }
    return ans;
}

void c726_countOfAtoms::test()
{
    cout<<"==="<<endl;
    int index = 0;
    cout<<countOfAtoms("Mg(OH)2")<<endl;
    cout<<"=== end"<<endl;
}
