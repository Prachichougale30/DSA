#include<bits/stdc++.h>
using namespace std;
// node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
class Solution {
  public:
    Node* revLL(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        Node* forw = NULL;
        
        while (curr) {
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }

    Node* removeLeadingZeros(Node* head) {
        while (head && head->data == 0 && head->next) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        return head;
    }
    
    Node* addTwoLists(Node* num1, Node* num2) {
        num1 = revLL(num1);
        num2 = revLL(num2);
        
        Node* ans = new Node(-1);
        Node* temp = ans;
        int carry = 0;

        while (num1 || num2 || carry) {
            int sum = 0;
            if (num1) {
                sum += num1->data;
                num1 = num1->next;
            }
            if (num2) {
                sum += num2->data;
                num2 = num2->next;
            }
            sum += carry;

            Node* newNode = new Node(sum % 10);
            carry = sum / 10;
            temp->next = newNode;
            temp = temp->next;
        }

        Node* result = revLL(ans->next);
        result = removeLeadingZeros(result);
        return result;
    }
};
