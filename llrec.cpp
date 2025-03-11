#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    smaller = nullptr;
    larger = nullptr;
    if (head==nullptr) return;
    Node* nextnode = head->next;
    head->next=nullptr;
    if(head->val<=pivot)
    {
        smaller = head;
        llpivot(nextnode, smaller->next,larger,pivot);
    }
    if(head->val>pivot)
    {
        larger = head;
        llpivot(nextnode, smaller,larger->next,pivot);
    }
    head=nullptr;
}
