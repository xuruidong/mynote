#ifndef C274_HINDEX_H
#define C274_HINDEX_H

#include "common.h"

class c274_hIndex
{
    public:
        c274_hIndex();
        virtual ~c274_hIndex();
        int hIndex(vector<int>& citations) ;
        void test();

    protected:

    private:
};

#endif // C274_HINDEX_H
