#include <bits/stdc++.h>
using namespace std;

// Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// ---------------- Traversals ----------------

// Iterative Preorder (N → L → R)
vector<int> preorder(Node* root) {
    vector<int> ans;
    if (root == NULL) return ans;

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* curr = st.top();
        st.pop();

        ans.push_back(curr->data);   // Visit node

        if (curr->right) st.push(curr->right); // Push right first
        if (curr->left) st.push(curr->left);   // Then left
    }
    return ans;
}

// Iterative Inorder (L → N → R)
vector<int> inorder(Node* root) {
    vector<int> ans;
    stack<Node*> st;
    Node* curr = root;

    while (curr != NULL || !st.empty()) {
        while (curr != NULL) {       // Go as left as possible
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top(); st.pop();
        ans.push_back(curr->data);   // Visit node
        curr = curr->right;          // Go right
    }
    return ans;
}

// Iterative Postorder (L → R → N) using two stacks
vector<int> postorder(Node* root) {
    vector<int> ans;
    if (root == NULL) return ans;

    stack<Node*> st1, st2;
    st1.push(root);

    while (!st1.empty()) {
        Node* curr = st1.top();
        st1.pop();
        st2.push(curr);

        if (curr->left) st1.push(curr->left);
        if (curr->right) st1.push(curr->right);
    }
    while (!st2.empty()) {
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return ans;
}

// ---------------- Helper Functions ----------------

// Build tree from user input (level-order input with -1 as NULL)
Node* buildTree() {
    cout << "Enter root value (-1 for NULL): ";
    int val;
    cin >> val;
    if (val == -1) return NULL;

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << "Enter left child of " << curr->data << " (-1 for NULL): ";
        int leftVal;
        cin >> leftVal;
        if (leftVal != -1) {
            curr->left = new Node(leftVal);
            q.push(curr->left);
        }

        cout << "Enter right child of " << curr->data << " (-1 for NULL): ";
        int rightVal;
        cin >> rightVal;
        if (rightVal != -1) {
            curr->right = new Node(rightVal);
            q.push(curr->right);
        }
    }
    return root;
}

// ---------------- Main ----------------
int main() {
    Node* root = buildTree();

    vector<int> pre = preorder(root);
    vector<int> in = inorder(root);
    vector<int> post = postorder(root);

    cout << "\nPreorder Traversal: ";
    for (int x : pre) cout << x << " ";

    cout << "\nInorder Traversal: ";
    for (int x : in) cout << x << " ";

    cout << "\nPostorder Traversal: ";
    for (int x : post) cout << x << " ";

    return 0;
}
