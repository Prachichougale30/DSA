#include <bits/stdc++.h>
using namespace std;

// ✅ Define Node class properly
class Node {
public:
    int data;      // Node value
    Node *left;    // Pointer to left child
    Node *right;   // Pointer to right child

    // Constructor to initialize node
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// ✅ ZigZag Traversal Solution Class
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        
        vector<int> result; // Stores the final zigzag order
        
        // Base case: empty tree
        if (root == NULL) {
            return result;
        }
        
        // Queue for BFS traversal
        queue<Node*> q;
        q.push(root);
        
        // Flag for direction (true = left->right, false = right->left)
        bool leftToRight = true;
        
        // Process level by level
        while (!q.empty()) {
            
            int size = q.size();        // Number of nodes at current level
            vector<int> ans(size);      // Temporary vector for current level
            
            for (int i = 0; i < size; i++) {
                Node* frontNode = q.front();
                q.pop();
                
                // Calculate index for zigzag order
                int index = leftToRight ? i : size - i - 1;
                ans[index] = frontNode->data;
                
                // Enqueue left and right children
                if (frontNode->left) q.push(frontNode->left);
                if (frontNode->right) q.push(frontNode->right);
            }
            
            // Flip direction for next level
            leftToRight = !leftToRight;
            
            // Merge this level into final result
            for (auto val : ans) {
                result.push_back(val);
            }
        }
        
        return result;
    }
};

// ✅ Example usage (main function)
int main() {
    // Creating sample tree
    /*
            1
           / \
          2   3
         / \ / \
        4  5 6  7
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    Solution sol;
    vector<int> res = sol.zigZagTraversal(root);
    
    cout << "ZigZag Traversal: ";
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
