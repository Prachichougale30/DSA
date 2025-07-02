// Link list Node
struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }

}; 
class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
     
    int getLength(Node* head){
       int count=0;
       
         while(head!=nullptr){
             count++;
             head=head->next;
         }
         return count;
    }
  
    
    int getMiddle(Node* head,int n) {
        // code her
        Node *temp=head;
         int midPosstion=(getLength(head)/2)+1,counter=0;
         
         while(temp){
             ++counter;
             if(n == counter)return temp->data;
             temp=temp->next;
         }
         return 0;
         
    }
   
};