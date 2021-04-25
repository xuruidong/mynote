#include "c28_strstr.h"

c28_strstr::c28_strstr()
{
    //ctor
}

c28_strstr::~c28_strstr()
{
    //dtor
}

int c28_strstr::strStr(string haystack, string needle)
{
    if(needle == ""){
        return 0;
    }
    if(needle.size() > haystack.size()){
        return -1;
    }

    for(int i=0; i<int(haystack.size())-int(needle.size())+1; ++i){
        int j=0;
        for(; j<needle.size(); ++j){
            if(needle[j] != haystack[i+j]){
                break;
            }
        }
        if(j==needle.size())
            return i;
    }
    return -1;
}
