#ifndef C802_EVENTUALSAFENODES_H
#define C802_EVENTUALSAFENODES_H

#include "common.h"

class c802_eventualSafeNodes
{
    public:
        c802_eventualSafeNodes();
        virtual ~c802_eventualSafeNodes();
        vector<int> eventualSafeNodes(vector<vector<int>>& graph);
        void test();

    protected:

    private:
};

#endif // C802_EVENTUALSAFENODES_H
