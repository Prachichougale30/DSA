#include<bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



class Solution {
public:
    
    void inorder(Node* root, vector<int>& arr) {
        if(root == NULL)
            return;
            
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
    
    void preorderFill(Node* root, vector<int>& arr, int &index) {
        if(root == NULL)
            return;
            
        // Fill root first (Min Heap property)
        root->data = arr[index++];
        
        preorderFill(root->left, arr, index);
        preorderFill(root->right, arr, index);
    }
    
    void convertToMinHeap(Node* root) {
        
        vector<int> arr;
        
        // Step 1: Store BST elements in sorted order
        inorder(root, arr);
        
        int index = 0;
        
        // Step 2: Fill tree using preorder
        preorderFill(root, arr, index);
    }
};