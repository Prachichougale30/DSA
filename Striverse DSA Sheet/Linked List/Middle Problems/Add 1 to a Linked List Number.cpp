#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
class Solution {
  public:
    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* temp = head;

        while (temp != NULL) {
            Node* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    Node* addOne(Node* head) {

        head = reverseList(head);

        int carry = 1;
        Node* current = head;

        while(current && carry){
            int sum = current->data + carry;
            current->data = sum % 10;
            carry = sum / 10;

            if(!current->next && carry){
                current->next = new Node(carry);
                carry = 0;
            }

            current = current->next;
        }

        head = reverseList(head);
        return head;
    }
};