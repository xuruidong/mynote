#include "c160_getIntersectionNode.h"
#include "common.h"

c160_getIntersectionNode::c160_getIntersectionNode()
{
    //ctor
}

c160_getIntersectionNode::~c160_getIntersectionNode()
{
    //dtor
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    unordered_set<ListNode *> uset;
    ListNode *pa = headA;
    ListNode *pb = headB;
    while(pa || pb) {
        if(pa) {
            if(uset.find(pa) != uset.end()) {
                return pa;
            }
            uset.insert(pa);
            pa = pa->next;
        }
        if(pb) {
            if(uset.find(pb) != uset.end()) {
                return pb;
            }
            uset.insert(pb);
            pb = pb->next;
        }
    }
    return nullptr;
}

ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB)
{
    ListNode *pa = headA;
    ListNode *pb = headB;
    int la=0, lb=0;
    while(pa) {
        ++la;
        pa = pa->next;
    }
    while(pb) {
        ++lb;
        pb = pb->next;
    }

    pa = headA;
    pb = headB;
    if(la>lb) {
        int delta = la-lb;
        while(delta){
            pa = pa->next;
            --delta;
        }
    }
    if(la <= lb) {
        int delta = lb - la;
        while(delta){
            pb = pb->next;
            --delta;
        }
    }
    while(pa) {
        if(pa == pb) {
            return pa;
        }
        pa = pa->next;
        pb = pb->next;
    }

    return nullptr;
}
