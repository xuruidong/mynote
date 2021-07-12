#ifndef C981_TIMEMAP_H
#define C981_TIMEMAP_H

#include "common.h"

struct c981_stru {
    int timestamp;
    string value;
};

class c981_TimeMap
{
    public:
        c981_TimeMap();
        virtual ~c981_TimeMap();
        void set(string key, string value, int timestamp);
        string get(string key, int timestamp);
        void test();

    protected:

    private:
        unordered_map<string, vector<struct c981_stru>> umap;
};

#endif // C981_TIMEMAP_H
