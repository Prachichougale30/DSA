#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to delete given node without head
void deleteNode(Node* del_node) {
    if (del_node == NULL || del_node->next == NULL)
        return; // Can't delete the last node using this method

    Node* temp = del_node->next;
    del_node->data = temp->data; // Copy next node's data
    del_node->next = temp->next; // Bypass next node
    delete temp; // Delete the next node
}

// Helper function to print linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

// Example usage
int main() {
    // Creating linked list: 10->20->4->30
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(4);
    head->next->next->next = new Node(30);

    // Let's delete node with value 20 (we only have pointer to that node)
    Node* del_node = head->next; // Node with value 20

    deleteNode(del_node);

    printList(head); // Output: 10->4->30

    return 0;
}
