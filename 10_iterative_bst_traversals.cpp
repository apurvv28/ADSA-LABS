#include <iostream>
#include <stack>
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

void inorderIt(Node *root)
{
    stack<Node *> st;
    Node *cur = root;
    while (cur || !st.empty())
    {
        while (cur)
        {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        st.pop();
        cout << cur->key << ' ';
        cur = cur->right;
    }
    cout << "\n";
}

void preorderIt(Node *root)
{
    if (!root)
    {
        cout << "\n";
        return;
    }
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *cur = st.top();
        st.pop();
        cout << cur->key << ' ';
        if (cur->right)
            st.push(cur->right);
        if (cur->left)
            st.push(cur->left);
    }
    cout << "\n";
}

void postorderIt(Node *root)
{
    if (!root)
    {
        cout << "\n";
        return;
    }
    stack<Node *> s1, s2;
    s1.push(root);
    while (!s1.empty())
    {
        Node *cur = s1.top();
        s1.pop();
        s2.push(cur);
        if (cur->left)
            s1.push(cur->left);
        if (cur->right)
            s1.push(cur->right);
    }
    while (!s2.empty())
    {
        cout << s2.top()->key << ' ';
        s2.pop();
    }
    cout << "\n";
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
    inorderIt(root);
    preorderIt(root);
    postorderIt(root);
    return 0;
}


// Time Complexity: O(N)
// Space Complexity: O(H)

// Example Input:
// 5
// 5 3 7 1 9
