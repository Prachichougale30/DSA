#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *prev;
    Node *next;

    // Constructor
    Node(int d) {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

// Print the linked list
void print(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Get length of DLL
int getlength(Node *head) {
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

// Insert at head
void insertAtHead(Node *&head, Node *&tail, int d) {
    Node *temp = new Node(d);
    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

// Insert at tail
void insertAtTail(Node *&tail, Node *&head, int d) {
    Node *temp = new Node(d);
    if (tail == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

// Insert at position
void insertAtPosition(Node *&tail, Node *&head, int position, int d) {
    if (position == 1) {
        insertAtHead(head, tail, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    // Insert at end
    if (temp->next == NULL) {
        insertAtTail(tail, head, d);
        return;
    }

    // Inserting in middle
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    nodeToInsert->prev = temp;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 11);
    print(head);

    insertAtHead(head, tail, 12);
    print(head);

    insertAtHead(head, tail, 13);
    print(head);

    insertAtTail(tail, head, 30);
    print(head);

    insertAtPosition(tail, head, 3, 17);
    print(head);

    return 0;
}
