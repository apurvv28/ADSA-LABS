#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int value)
{
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

Node* minValue(Node* root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

Node* deleteNode(Node* root, int key)
{
    if (root == NULL)
        return NULL;

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }

    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }

    else
    {
        if (root->left == NULL)
        {
            return root->right;
        }

        else if (root->right == NULL)
        {
            return root->left;
        }

        Node* temp = minValue(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(Node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    Node* root = NULL;

    for (int i = 0; i < n; i++)
    {
        int value;
        cout << "Enter node " << (i+1) << ": ";
        cin >> value;

        root = insert(root, value);
    }

    int key;
    cout << "Enter key to delete: ";
    cin >> key;

    root = deleteNode(root, key);

    cout << "\nInorder Traversal after deletion: ";
    inorder(root);
}


// Time Complexity: O(H) average, O(N) worst
// Space Complexity: O(H)

// Example Input:
// Enter number of nodes: 5
// Enter node 1: 5
// Enter node 2: 3
// Enter node 3: 7
// Enter node 4: 1
// Enter node 5: 9
// Enter key to delete: 3
