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

void inorder(Node *r)
{
    if (!r)
        return;
    inorder(r->left);
    cout << r->key << ' ';
    inorder(r->right);
}
void preorder(Node *r)
{
    if (!r)
        return;
    cout << r->key << ' ';
    preorder(r->left);
    preorder(r->right);
}
void postorder(Node *r)
{
    if (!r)
        return;
    postorder(r->left);
    postorder(r->right);
    cout << r->key << ' ';
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
    preorder(root);
    cout << "\n";
    postorder(root);
    cout << "\n";
    return 0;
}


// Time Complexity: O(N)
// Space Complexity: O(H)

// Example Input:
// 5
// 5 3 7 1 9
