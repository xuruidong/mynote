#ifndef C502_FINDMAXIMIZEDCAPITAL_H
#define C502_FINDMAXIMIZEDCAPITAL_H

#include "common.h"

class c502_findMaximizedCapital
{
    public:
        c502_findMaximizedCapital();
        virtual ~c502_findMaximizedCapital();
        int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int>& capital);
        void test();

    protected:

    private:
};

#endif // C502_FINDMAXIMIZEDCAPITAL_H
