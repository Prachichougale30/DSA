#include<bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution {
  public:
    // Function to remove duplicates from sorted linked list.
    Node* removeDuplicates(Node* head) {

        // code here
        Node*prev=NULL;
        Node* curr=head;
        while(curr){
            if(curr!=NULL && prev!=NULL and prev->data==curr->data){
                prev->next=curr->next;
                curr=prev->next;
            }
            else{
            prev=curr;
            curr=curr->next;
            }
         
        }
         return head;
    }
};