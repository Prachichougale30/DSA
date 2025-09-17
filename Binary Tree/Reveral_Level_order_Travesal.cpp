// A recursive C++ program to print
// reverse level order traversal
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

// Function to find the height of
// the tree.
int height(Node *node) {
    if (node == nullptr)
        return 0;

    int lheight = height(node->left);
    int rheight = height(node->right);

    return max(lheight, rheight) + 1;
}

// Print nodes at a given level
void printGivenLevel(Node *root, int nodeLevel, int reqLevel) {
    if (root == nullptr)
        return;

    // if the required level is reached,
    // then print the node.
    if (nodeLevel == reqLevel)
        cout << root->data << " ";

    // else call function for left and
    // right subtree.
    else if (nodeLevel < reqLevel) {
        printGivenLevel(root->left, nodeLevel + 1, reqLevel);
        printGivenLevel(root->right, nodeLevel + 1, reqLevel);
    }
}

// Function to print reverse
// level order traversal a tree
void reverseLevelOrder(Node *root) {

    // find the height of the tree.
    int h = height(root);

    // Start printing from the lowest level.
    for (int i = h; i >= 1; i--)
        printGivenLevel(root, 1, i);
}

int main() {

    // create hard coded tree
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    reverseLevelOrder(root);

    return 0;
}