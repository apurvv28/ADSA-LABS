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
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

bool search(Node* root, int key)
{
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
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
    cout << "Enter key to search: ";
    cin >> key;

    cout << "\nResult: ";
    if (search(root, key))
        cout << "FOUND";
    else
        cout << "NOT FOUND";
}


// Time Complexity: O(H) average, O(N) worst
// Space Complexity: O(1) or O(H)

// Example Input:
// Enter number of nodes: 5
// Enter node 1: 5
// Enter node 2: 3
// Enter node 3: 7
// Enter node 4: 1
// Enter node 5: 9
// Enter key to search: 3
