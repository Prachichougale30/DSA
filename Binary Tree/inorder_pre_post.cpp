#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node *left, *right;

    node(int d) {
        data = d;
        left = right = NULL;
    }
};

node* buildTree(node* root) {
    cout << "Enter data:" << endl;
    int data;
    cin >> data;

    if (data == -1) return NULL;

    root = new node(data);

    cout << "Enter left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

// Inorder Traversal (LNR)
void inorder(node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder Traversal (NLR)
void preorder(node* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal (LRN)
void postorder(node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    node* root = NULL;
    root = buildTree(root);

    cout << "\nInorder traversal: ";
    inorder(root);

    cout << "\nPreorder traversal: ";
    preorder(root);

    cout << "\nPostorder traversal: ";
    postorder(root);

    return 0;
}
