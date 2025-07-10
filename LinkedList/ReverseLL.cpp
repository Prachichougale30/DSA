#include <iostream>
using namespace std;

// Linked List Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
public:
    Node* reverseList(Node* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        Node* prev = NULL;
        Node* curr = head;
        Node* forward = NULL;

        while (curr != NULL) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
};

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Main function
int main() {
    // Creating linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printList(head);

    // Reverse the list using the Solution class
    Solution sol;
    Node* reversedHead = sol.reverseList(head);

    cout << "Reversed List: ";
    printList(reversedHead);

    return 0;
}
