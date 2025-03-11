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
    if(head->val<=pivot)
    {
        smaller = head;
        smaller->next=nullptr;
        return llpivot(nextnode, smaller->next,larger,pivot);
    }
    if(head->val>pivot)
    {
        larger = head;
        larger->next=nullptr;
        return llpivot(nextnode, smaller,larger->next,pivot);
    }
}



