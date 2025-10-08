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
    int height(Node* node) {
        if (node == NULL) {
            return -1;  // empty tree has height -1 (so leaf = 0)
        }
        
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        
        return max(leftHeight, rightHeight) + 1;
    }
  public:
    bool isBalanced(Node* root) {
        // code here
        if(root==NULL){
            return true;
        }
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        
        bool diff=abs(height(root->left)-height(root->right))<=1;
        
        if(left && right && diff){
            return 1;
        }
        else{
            return false;
        }
    }
};