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

int check(Node *r)
{
    if (!r)
        return 0;
    int hl = check(r->left);
    if (hl == -1)
        return -1;
    int hr = check(r->right);
    if (hr == -1)
        return -1;
    int diff = hl - hr;
    if (diff < 0)
        diff = -diff;
    if (diff > 1)
        return -1;
    return 1 + (hl > hr ? hl : hr);
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
    cout << (check(root) == -1 ? "NOT BALANCED\n" : "BALANCED\n");
    return 0;
}


// Time Complexity: O(N log N) or O(N)
// Space Complexity: O(H)

// Example Input:
// 5
// 1 2 3 4 5
