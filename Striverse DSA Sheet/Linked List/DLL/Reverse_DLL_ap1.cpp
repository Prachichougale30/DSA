#include <iostream>
#include <stack>
using namespace std;

// Definition of Node for Doubly Linked List
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Function to insert node at end
Node* insertAtEnd(Node* head, int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Function to print Doubly Linked List
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to reverse a doubly linked list using stack (Brute Force)
Node* reverseDLL(Node* head) {

    // If list is empty or has only one node
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    stack<int> st;

    Node* temp = head;

    // Push all data into stack
    while (temp != nullptr) {
        st.push(temp->data);
        temp = temp->next;
    }

    // Replace data from stack
    temp = head;
    while (temp != nullptr) {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
}

// Main function
int main() {
    Node* head = nullptr;

    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);

    cout << "Original List: ";
    printList(head);

    head = reverseDLL(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}