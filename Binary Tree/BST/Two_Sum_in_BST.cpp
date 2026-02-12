#include <bits/stdc++.h>
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

    void inorder(Node* root, vector<int>& in) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, in);
        in.push_back(root->data);
        inorder(root->right, in);
    }

    bool findTarget(Node* root, int target) {
        vector<int> inorderVal;

        // store inorder (sorted values)
        inorder(root, inorderVal);

        // two pointer approach
        int i = 0, j = inorderVal.size() - 1;

        while (i < j) {
            int sum = inorderVal[i] + inorderVal[j];

            if (sum == target) {
                return true;
            }
            else if (sum > target) {
                j--;
            }
            else {
                i++;
            }
        }
        return false;
    }
};
