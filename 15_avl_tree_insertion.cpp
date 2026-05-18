#include <iostream>
using namespace std;

struct Node
{
    int key;
    int h;
    Node *left;
    Node *right;
    Node(int v) : key(v), h(1), left(nullptr), right(nullptr) {}
};

int height(Node *n) { return n ? n->h : 0; }
int bal(Node *n) { return n ? height(n->left) - height(n->right) : 0; }
int mx(int a, int b) { return a > b ? a : b; }

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *t2 = x->right;
    x->right = y;
    y->left = t2;
    y->h = 1 + mx(height(y->left), height(y->right));
    x->h = 1 + mx(height(x->left), height(x->right));
    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *t2 = y->left;
    y->left = x;
    x->right = t2;
    x->h = 1 + mx(height(x->left), height(x->right));
    y->h = 1 + mx(height(y->left), height(y->right));
    return y;
}

Node *insertNode(Node *node, int key)
{
    if (!node)
        return new Node(key);
    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
    else
        return node;

    node->h = 1 + mx(height(node->left), height(node->right));
    int b = bal(node);

    if (b > 1 && key < node->left->key)
        return rightRotate(node);
    if (b < -1 && key > node->right->key)
        return leftRotate(node);
    if (b > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (b < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void inorder(Node *r)
{
    if (!r)
        return;
    inorder(r->left);
    cout << r->key << ' ';
    inorder(r->right);
}

int main()
{
    int n;
    cin >> n;
    Node *root = nullptr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        root = insertNode(root, x);
    }
    inorder(root);
    cout << "\n";
    return 0;
}


// Time Complexity: O(log N)
// Space Complexity: O(log N)

// Example Input:
// 5
// 1 2 3 4 5
