#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};



class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        // code goes here.
      Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* dummy = new Node(-1); 
    Node* tail = dummy;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->data == ptr2->data) {
          
            tail->next = new Node(ptr1->data);
            tail = tail->next;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->data < ptr2->data) {
            ptr1 = ptr1->next;
        }
        else {
            ptr2 = ptr2->next;
        }
    }
    return dummy->next; // skipping dummy node
}
};