#include<bits/stdc++.h>
using namespace std;
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
class Solution {
  public:
  
    void inorder(Node* root, vector<int>& in) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, in);
        in.push_back(root->data);
        inorder(root->right, in);
    }
  
    Node *flattenBST(Node *root) {
        vector<int> inorderVal;

        // Step 1: store inorder (sorted values)
        inorder(root, inorderVal);

        int n = inorderVal.size();
        if (n == 0) return NULL;

        // Step 2: create new root
        Node* Newroot = new Node(inorderVal[0]);
        Node* curr = Newroot;

        // Step 3: create right-skewed tree
        for (int i = 1; i < n; i++) {
            Node* temp = new Node(inorderVal[i]);
            curr->left = NULL;
            curr->right = temp;
            curr = temp;
        }

        // Step 4: last node
        curr->left = NULL;
        curr->right = NULL;

        return Newroot;
    }
};
