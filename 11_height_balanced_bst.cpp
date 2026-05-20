#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node *insert(Node *root, int value)
{
    if (root == NULL)
    {
        return new Node(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }

    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

int checkBalance(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = checkBalance(root->left);

    if (leftHeight == -1)
    {
        return -1;
    }

    int rightHeight = checkBalance(root->right);

    if (rightHeight == -1)
    {
        return -1;
    }

    int diff = leftHeight - rightHeight;

    if (diff < 0)
    {
        diff = -diff;
    }

    if (diff > 1)
    {
        return -1;
    }

    if (leftHeight > rightHeight)
    {
        return leftHeight + 1;
    }

    return rightHeight + 1;
}

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    Node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        int value;
        cout << "Enter node " << (i+1) << ": ";
        cin >> value;
        root = insert(root, value);
    }
    cout << "\nResult: ";
    if (checkBalance(root) == -1)
    {
        cout << "NOT BALANCED";
    }
    else
    {
        cout << "BALANCED";
    }
}

// Time Complexity: O(N log N) or O(N)
// Space Complexity: O(H)

// Example Input:
// Enter number of nodes: 5
// Enter node 1: 1
// Enter node 2: 2
// Enter node 3: 3
// Enter node 4: 4
// Enter node 5: 5
