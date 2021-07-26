#include "c138_copyRandomList.h"

c138_copyRandomList::c138_copyRandomList()
{
    //ctor
}

c138_copyRandomList::~c138_copyRandomList()
{
    //dtor
}

// 8 ms
Node* copyRandomList(Node* head)
{
    unordered_map<Node *, Node *> umap;
    Node *ans = nullptr;
    Node *p = head;
//    if(!head) {
//        return nullptr;
//    }
    Node *pre = nullptr;
    while(p) {
        Node *np = new Node(p->val);
        if (ans == nullptr) {
            ans = np;
        }
        else {
            pre->next = np;
        }
        pre = np;

        umap[p] = np;
        p = p->next;
    }

    p = head;
    Node *np = ans;
    while(p) {
        np->random = umap[p->random];
        p = p->next;
        np = np->next;
    }
    return ans;
}

Node* copyRandomList(Node* head)
{
    unordered_map<Node *, Node *> umap;
    Node fake(0);
    Node *ans = &fake;
    Node *p = head;
    Node *pre = ans;

    while(p) {
        Node *np = new Node(p->val);
        pre->next = np;
        pre = np;

        umap[p] = np;
        p = p->next;
    }

    p = head;
    ans = ans->next;
    Node *np = ans;
    while(p) {
        np->random = umap[p->random];
        p = p->next;
        np = np->next;
    }
    return ans;
}
