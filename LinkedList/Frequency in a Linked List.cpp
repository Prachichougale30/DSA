#include<iostream>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
class Solution{
    public:
    int count(Node*head,int key){
        int count=0;
        Node*curr=head;
        while (curr!=NULL)
        {
if(curr->data==key){
    count++;
   
}
 curr=curr->next;
        }
       return count; 
    }
};