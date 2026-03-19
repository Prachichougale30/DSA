#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to find nth node
Node* findNthNode(Node* temp, int k) {
    int cnt = 1;
    while (temp != NULL) {
        if (cnt == k) return temp;
        cnt++;
        temp = temp->next;
    }
    return temp;
}

// Function to rotate linked list by k positions
Node* rotate(Node* head, int k) {
    if (head == NULL || k == 0) return head;

    Node* tail = head;
    int len = 1;

    // Find length and last node
    while (tail->next != NULL) {
        tail = tail->next;
        len++;
    }

    // If k is multiple of length
    if (k % len == 0) return head;

    k = k % len;

    // Make it circular
    tail->next = head;

    // Find new last node
    Node* newLastNode = findNthNode(head, len - k);

    // Break the circle
    head = newLastNode->next;
    newLastNode->next = NULL;

    return head;
}

// Function to print linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Driver code
int main() {
    // Creating linked list: 1->2->3->4->5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List:\n";
    printList(head);

    int k = 2;
    head = rotate(head, k);

    cout << "After rotating by " << k << " positions:\n";
    printList(head);

    return 0;
}