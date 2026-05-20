#include <iostream>
using namespace std;

struct Node
{
    int data;
    int height;

    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        height = 1;

        left = NULL;
        right = NULL;
    }
};

int getHeight(Node* root)
{
    if (root == NULL)
        return 0;

    return root->height;
}

int getBalance(Node* root)
{
    if (root == NULL)
        return 0;

    return getHeight(root->left) - getHeight(root->right);
}

int maxValue(int a, int b)
{
    if (a > b)
        return a;

    return b;
}

Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* t = x->right;

    x->right = y;
    y->left = t;

    y->height = maxValue(getHeight(y->left), getHeight(y->right)) + 1;

    x->height = maxValue(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x)
{
    Node* y = x->right;
    Node* t = y->left;

    y->left = x;
    x->right = t;

    x->height = maxValue(getHeight(x->left), getHeight(x->right)) + 1;

    y->height = maxValue(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

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

    root->height =
        maxValue(getHeight(root->left), getHeight(root->right)) + 1;

    int balance = getBalance(root);

    if (balance > 1 && value < root->left->data)
    {
        return rightRotate(root);
    }

    if (balance < -1 && value > root->right->data)
    {
        return leftRotate(root);
    }

    if (balance > 1 && value > root->left->data)
    {
        root->left = leftRotate(root->left);

        return rightRotate(root);
    }

    if (balance < -1 && value < root->right->data)
    {
        root->right = rightRotate(root->right);

        return leftRotate(root);
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
        cin >> value;

        root = insert(root, value);
    }

    inorder(root);
}


// Time Complexity: O(log N)
// Space Complexity: O(log N)

// Example Input:
// Enter number of nodes: 5
// Enter node 1: 1
// Enter node 2: 2
// Enter node 3: 3
// Enter node 4: 4
// Enter node 5: 5
