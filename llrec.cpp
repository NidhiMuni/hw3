#include "llrec.h"

//added
using namespace std;
#include <iostream>

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){  
  smaller = nullptr;
  larger = nullptr;
  if (head != nullptr){
    if (head->val <= pivot){ 
      Node* temp = head;
      head = head->next;
      smaller = temp;
      smaller->next = nullptr;
      llpivot(head, smaller->next, larger, pivot);
    } else if (head->val > pivot){
      Node* temp = head;
      head = head->next;
      larger = temp;
      larger->next = nullptr;
      llpivot(head, smaller, larger->next, pivot);
    }
  }
}
