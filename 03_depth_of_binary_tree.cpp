#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

int height(Node *r)
{
    if (!r)
        return 0;
    int hl = height(r->left);
    int hr = height(r->right);
    return 1 + (hl > hr ? hl : hr);
}

int main()
{

    int n;
    cin >> n;
    if (n <= 0)
    {
        cout << 0 << "\n";
        return 0;
    }
    int x;
    cin >> x;
    Node *root = new Node(x);
    queue<Node *> q;
    q.push(root);
    int i = 1;
    while (i < n)
    {
        Node *cur = q.front();
        q.pop();
        if (i < n)
        {
            cin >> x;
            cur->left = new Node(x);
            q.push(cur->left);
            i++;
        }
        if (i < n)
        {
            cin >> x;
            cur->right = new Node(x);
            q.push(cur->right);
            i++;
        }
    }
    cout << height(root) << "\n";
    return 0;
}


// Time Complexity: O(N)
// Space Complexity: O(H)

// Example Input:
// 5
// 1 2 3 4 5
