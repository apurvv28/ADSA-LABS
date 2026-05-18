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

void inorder(Node *r)
{
    if (!r)
        return;
    inorder(r->left);
    cout << r->data << ' ';
    inorder(r->right);
}
void preorder(Node *r)
{
    if (!r)
        return;
    cout << r->data << ' ';
    preorder(r->left);
    preorder(r->right);
}
void postorder(Node *r)
{
    if (!r)
        return;
    postorder(r->left);
    postorder(r->right);
    cout << r->data << ' ';
}

int main()
{

    int n;
    cin >> n;
    if (n <= 0)
        return 0;
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

    inorder(root);
    cout << "\n";
    preorder(root);
    cout << "\n";
    postorder(root);
    cout << "\n";
    return 0;
}


// Time Complexity: O(N)
// Space Complexity: O(H) where H is height

// Example Input:
// 5
// 1 2 3 4 5
