#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int v) : key(v), left(nullptr), right(nullptr) {}
};

Node *insertNode(Node *r, int x)
{
    if (!r)
        return new Node(x);
    if (x < r->key)
        r->left = insertNode(r->left, x);
    else if (x > r->key)
        r->right = insertNode(r->right, x);
    return r;
}

Node *minNode(Node *r)
{
    while (r && r->left)
        r = r->left;
    return r;
}

Node *deleteNode(Node *r, int k)
{
    if (!r)
        return nullptr;
    if (k < r->key)
        r->left = deleteNode(r->left, k);
    else if (k > r->key)
        r->right = deleteNode(r->right, k);
    else
    {
        if (!r->left)
        {
            Node *t = r->right;
            delete r;
            return t;
        }
        if (!r->right)
        {
            Node *t = r->left;
            delete r;
            return t;
        }
        Node *s = minNode(r->right);
        r->key = s->key;
        r->right = deleteNode(r->right, s->key);
    }
    return r;
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
    int key;
    cin >> key;
    root = deleteNode(root, key);
    inorder(root);
    cout << "\n";
    return 0;
}


// Time Complexity: O(H) average, O(N) worst
// Space Complexity: O(H)

// Example Input:
// 5
// 5 3 7 1 9
// 3
