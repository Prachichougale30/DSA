#include <iostream>
#include <vector>
using namespace std;

// Definition for binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
public:

    // Step 1: Store inorder traversal
    void inorder(TreeNode* root, vector<int>& in) {
        if (root == nullptr)
            return;

        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }

    // Step 2: Convert sorted inorder array to balanced BST
    TreeNode* inorderToBST(int s, int e, vector<int>& in) {
        if (s > e)
            return nullptr;

        int mid = (s + e) / 2;

        TreeNode* root = new TreeNode(in[mid]);

        root->left = inorderToBST(s, mid - 1, in);
        root->right = inorderToBST(mid + 1, e, in);

        return root;
    }

    // Step 3: Balance BST
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorderVal;

        inorder(root, inorderVal);

        return inorderToBST(0, inorderVal.size() - 1, inorderVal);
    }
};

// Helper: Insert into BST
TreeNode* insertBST(TreeNode* root, int val) {
    if (root == nullptr)
        return new TreeNode(val);

    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}

// Helper: Print inorder
void printInorder(TreeNode* root) {
    if (root == nullptr)
        return;

    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {

    TreeNode* root = nullptr;

    // Create unbalanced BST
    root = insertBST(root, 10);
    root = insertBST(root, 20);
    root = insertBST(root, 30);
    root = insertBST(root, 40);
    root = insertBST(root, 50);

    cout << "Original BST (Inorder): ";
    printInorder(root);
    cout << endl;

    Solution obj;
    TreeNode* balancedRoot = obj.balanceBST(root);

    cout << "Balanced BST (Inorder): ";
    printInorder(balancedRoot);
    cout << endl;

    return 0;
}
