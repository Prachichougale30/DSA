#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
} 
class Solution {
  public:
   int length(Node*head){
       int count=0;
       Node*temp=head;
        while(head){
             count++;
             head=head->next;
         }
         return count;
   }
   Node* rotate(Node*head,int k){
       if(!head|| !head->next || k==0)
         return head;
         int len=length(head);
         int rotations=k%len;
        if(rotations==0){
            return head;
        }
         Node*current=head;
         for(int i=1;i<rotations;i++){
             current=current->next;
         }
         Node*newHead=current->next;
         current->next=NULL;
         
                 Node*temp=newHead;

                while(temp && temp->next){
             temp=temp->next;
         }
         if(temp){
             temp->next=head;
         }
         return newHead;
   }

};