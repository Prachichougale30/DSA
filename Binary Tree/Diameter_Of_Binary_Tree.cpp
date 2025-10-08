#include <bits/stdc++.h>
using namespace std;

// Binary Tree Node structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    // Helper function that returns pair {height, diameter}
    pair<int, int> diameterFast(Node* root) {
        if (root == NULL)
            return {0, 0}; // {height, diameter}
        
        // Recursive calls
        pair<int, int> left = diameterFast(root->left);
        pair<int, int> right = diameterFast(root->right);
        
        // Heights of left and right subtrees
        int leftHeight = left.first;
        int rightHeight = right.first;
        
        // Diameters of left and right subtrees
        int leftDiameter = left.second;
        int rightDiameter = right.second;
        
        // Current node's height
        int currHeight = 1 + max(leftHeight, rightHeight);
        
        // Diameter passing through current node
        int currDiameter = max(leftHeight + rightHeight, max(leftDiameter, rightDiameter));
        
        // Return pair of {height, diameter}
        return {currHeight, currDiameter};
    }
    
    // Main function to return diameter of binary tree
    int diameter(Node* root) {
        return diameterFast(root).second;
    }
};

// Helper function to build tree from level order input
Node* buildTree(vector<int> arr) {
    if (arr.empty()) return NULL;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        Node* curr = q.front();
        q.pop();

        // Add left child if available
        if (i < arr.size()) {
            curr->left = new Node(arr[i++]);
            q.push(curr->left);
        }

        // Add right child if available
        if (i < arr.size()) {
            curr->right = new Node(arr[i++]);
            q.push(curr->right);
        }
    }

    return root;
}

// Driver Code
int main() {
    // Example Input: You can modify this vector
    vector<int> arr = {5, 8, 6, 3, 7, 9};
    
    Node* root = buildTree(arr);

    Solution sol;
    cout << "Diameter of the binary tree: " << sol.diameter(root) << endl;

    return 0;
}
