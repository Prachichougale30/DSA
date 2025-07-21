#include<bits/stdc++.h>
using namespace std;

    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(!head || k==1) return head;
        
        Node*curr=head;
        Node*prev=NULL;
        Node*forw =NULL;
        
        int count=0;
        
        int totalNode=0;
        Node*temp=head;
        while(temp){
            totalNode++;
            temp=temp->next;
        }
       
        while(curr and count<k){
          forw=curr->next;
          curr->next=prev;
          prev=curr;
          curr=forw;
          count++;
        }
        if(forw!=NULL){
            head->next=reverseKGroup(forw,k);
        }
        return prev;
    }
};