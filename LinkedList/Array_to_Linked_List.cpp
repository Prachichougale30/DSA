#include <bits/stdc++.h>
using namespace std;

// Node structure for singly linked list
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Solution {
public:
    // Function to construct linked list from array
    Node* constructLL(vector<int>& arr) {
        if (arr.empty()) return nullptr;

        // Create head node
        Node* head = new Node(arr[0]);
        Node* tail = head;

        // Add rest of the elements
        for (int i = 1; i < arr.size(); i++) {
            Node* newNode = new Node(arr[i]);
            tail->next = newNode;
            tail = newNode;
        }

        return head;
    }
};

// Helper to print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Driver code
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    Solution obj;
    Node* head = obj.constructLL(arr);

    printList(head);  // Output: 1 -> 2 -> 3 -> 4 -> 5
    return 0;
}
