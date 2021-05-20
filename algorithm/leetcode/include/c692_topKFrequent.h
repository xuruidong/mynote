#ifndef C692_TOPKFREQUENT_H
#define C692_TOPKFREQUENT_H

#include "common.h"

class c692_topKFrequent
{
    public:
        c692_topKFrequent();
        virtual ~c692_topKFrequent();
        vector<string> topKFrequent(vector<string>& words, int k);
        void test();

    protected:

    private:
};

#endif // C692_TOPKFREQUENT_H
