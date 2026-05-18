#include <iostream>
#include <queue>
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
    if (!root)
        return 0;

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = (int)q.size();
        while (sz--)
        {
            Node *cur = q.front();
            q.pop();
            cout << cur->key << ' ';
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
        cout << "\n";
    }
    return 0;
}


// Time Complexity: O(N)
// Space Complexity: O(W) where W is max width

// Example Input:
// 5
// 5 3 7 1 9
