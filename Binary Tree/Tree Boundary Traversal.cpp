#include<bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:

    // 🔹 Function to traverse the left boundary (excluding leaf nodes)
    void traversalLeft(Node *root, vector<int> &ans) {
        // Base case: if root is null OR it's a leaf node → stop
        if (root == NULL || (root->left == NULL && root->right == NULL)) {
            return;
        }

        // Store current node (part of left boundary)
        ans.push_back(root->data);

        // Prefer going left; if no left, go right
        if (root->left) {
            traversalLeft(root->left, ans);
        } else {
            traversalLeft(root->right, ans);
        }
    }

    // 🔹 Function to traverse all leaf nodes (left to right)
    void traversalLeaf(Node *root, vector<int> &ans) {
        // Base case
        if (root == NULL) {
            return;
        }

        // If it's a leaf node → store it
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
            return;
        }

        // Recur for left and right subtrees
        traversalLeaf(root->left, ans);
        traversalLeaf(root->right, ans);
    }

    // 🔹 Function to traverse the right boundary (excluding leaf nodes)
    void traversalRight(Node *root, vector<int> &ans) {
        // Base case: stop for NULL or leaf
        if (root == NULL || (root->left == NULL && root->right == NULL)) {
            return;
        }

        // First traverse deeper on the right side
        if (root->right) {
            traversalRight(root->right, ans);
        } else {
            traversalRight(root->left, ans);
        }

        // ⚠️ Add current node *after recursion* 
        // to ensure reverse (bottom-up) order
        ans.push_back(root->data);
    }

    // 🔹 Main function for Boundary Traversal
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        
        // Empty tree check
        if (root == NULL)
            return ans;

        // 1️⃣ Add root node
        ans.push_back(root->data);

        // 2️⃣ Add left boundary (excluding leaf nodes)
        traversalLeft(root->left, ans);

        // 3️⃣ Add all leaf nodes (from both left & right subtrees)
        traversalLeaf(root->left, ans);
        traversalLeaf(root->right, ans);

        // 4️⃣ Add right boundary (excluding leaf nodes, in reverse)
        traversalRight(root->right, ans);

        // Return final boundary order
        return ans;
    }
};
