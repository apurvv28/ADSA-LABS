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

Node *searchNode(Node *r, int k)
{
    while (r && r->key != k)
    {
        if (k < r->key)
            r = r->left;
        else
            r = r->right;
    }
    return r;
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
    cout << (searchNode(root, key) ? "FOUND\n" : "NOT FOUND\n");
    return 0;
}


// Time Complexity: O(H) average, O(N) worst
// Space Complexity: O(1) or O(H)

// Example Input:
// 5
// 5 3 7 1 9
// 3
