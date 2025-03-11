#include "llrec.h"
#include <__config>

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    if(!smaller) smaller = nullptr;
    if(!larger) larger = nullptr;
    if (head==nullptr) return;
    Node* nextnode = head->next;
    if(head->val<=pivot)
    {
        smaller = head;
        smaller->next=NULL;
        return llpivot(nextnode, smaller->next,larger,pivot);
    }
    if(head->val>pivot)
    {
        larger = head;
        larger->next=NULL;
        return llpivot(nextnode, smaller,larger->next,pivot);
    }
}



