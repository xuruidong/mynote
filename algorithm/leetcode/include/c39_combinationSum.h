#ifndef C39_COMBINATIONSUM_H
#define C39_COMBINATIONSUM_H

#include "common.h"

class c39_combinationSum
{
    public:
        c39_combinationSum();
        virtual ~c39_combinationSum();
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target);
        vector<vector<int>> combinationSum3(vector<int>& candidates, int target);
        void test();

    protected:

    private:
};

#endif // C39_COMBINATIONSUM_H
