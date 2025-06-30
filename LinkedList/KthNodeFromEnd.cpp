#include <iostream>
using namespace std;

struct Node
{
    /* data */
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
class Solution{
    public:
    int getLength(Node* head){
        int count=0;
        while(head!=NULL){
            count++;
            head=head->next;
        }
        return count;
    }

    int getKthFromLast(Node*head,int k){
        Node* temp=head;
        int lastPossition=(getLength(head)+1)-k,counter=0;
        while (temp)
        {
            /* code */
            ++counter;
            if(lastPossition==counter)return temp->data;
            temp=temp->next;
        }
        return -1;
    }
};

