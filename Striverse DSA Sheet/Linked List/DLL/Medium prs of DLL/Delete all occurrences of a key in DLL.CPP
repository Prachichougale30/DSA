#include<bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
}; 
class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        
        Node* temp = *head_ref;
        
        while(temp != NULL){
            
            if(temp->data == x){
                
                Node* nextNode = temp->next;
                Node* prevNode = temp->prev;
                
                if(temp == *head_ref){
                    *head_ref = nextNode;
                }
                
                if(nextNode != NULL)
                    nextNode->prev = prevNode;
                    
                if(prevNode != NULL)
                    prevNode->next = nextNode;
                
                free(temp);
                
                temp = nextNode;
            }
            else{
                temp = temp->next;
            }
        }
    }
};