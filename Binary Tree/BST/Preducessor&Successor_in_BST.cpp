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
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* temp = root;
        Node* pred = NULL;
        Node* suc = NULL;

        while (temp != NULL && temp->data != key) {
            if (temp->data > key) {
                suc = temp;
                temp = temp->left;
            } else {
                pred = temp;
                temp = temp->right;
            }
        }

        if (temp == NULL)
            return {pred, suc};

        // predecessor
        Node* leftTree = temp->left;
        while (leftTree != NULL) {
            pred = leftTree;
            leftTree = leftTree->right;
        }

        // successor
        Node* rightTree = temp->right;
        while (rightTree != NULL) {
            suc = rightTree;
            rightTree = rightTree->left;
        }

        return {pred, suc};
    }
};
