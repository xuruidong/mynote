#ifndef C165_COMPAREVERSION_H
#define C165_COMPAREVERSION_H

#include "common.h"

class c165_compareVersion
{
    public:
        c165_compareVersion();
        virtual ~c165_compareVersion();
        int compareVersion(string version1, string version2);
        void test();

    protected:

    private:
};

#endif // C165_COMPAREVERSION_H
