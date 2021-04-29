#ifndef C983_RANGESUMBST_H
#define C983_RANGESUMBST_H

#include "common.h"

class c983_rangeSumBST
{
    public:
        c983_rangeSumBST();
        virtual ~c983_rangeSumBST();
        int rangeSumBST(TreeNode* root, int low, int high);
        int rangeSumBST2(TreeNode* root, int low, int high);

    protected:

    private:
};

#endif // C983_RANGESUMBST_H
