#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int findPosition(vector<int> &inorder, int element, int n) {
        for (int i = 0; i < n; i++) {
            if (inorder[i] == element) {
                return i;
            }
        }
        return -1;
    }

    Node* solve(vector<int> &inorder, vector<int> &preorder,
                int &index, int inorderStart, int inorderEnd, int n) {

        if (index >= n || inorderStart > inorderEnd) {
            return NULL;
        }

        int element = preorder[index++];
        Node* root = new Node(element);

        int position = findPosition(inorder, element, n);

        root->left = solve(inorder, preorder, index, inorderStart, position - 1, n);
        root->right = solve(inorder, preorder, index, position + 1, inorderEnd, n);

        return root;
    }

    Node* buildTree(vector<int> &inorder, vector<int> &preorder) {
        int n = inorder.size();
        int preOrderIndex = 0;

        return solve(inorder, preorder, preOrderIndex, 0, n - 1, n);
    }
};
