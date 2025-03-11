#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    if (head==NULL) return;
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



