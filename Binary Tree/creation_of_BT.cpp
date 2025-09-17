#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter data:" << endl;
    int data;
    cin >> data;

    if (data == -1)
    { // check first
        return NULL;
    }

    root = new node(data);

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node *root)
{
    if (root == NULL)
        return;

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        { //  use comparison
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL); // mark next level end
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
int main()
{
    node *root = NULL;
    // creating binary tree
    root = buildTree(root);

    // Example input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // Tree:
    //          1
    //       /     \
    //      3       5
    //     / \     /
    //    7  11   17

    cout << "Printing the level order traversal:" << endl;
    levelOrderTraversal(root);

    return 0;
}
