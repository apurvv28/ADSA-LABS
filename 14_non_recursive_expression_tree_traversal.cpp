#include <iostream>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

struct Node
{
    string val;
    Node *left;
    Node *right;
    Node(string v) : val(std::move(v)), left(nullptr), right(nullptr) {}
};

bool isOp(const string &t)
{
    return t.size() == 1 && (t[0] == '+' || t[0] == '-' || t[0] == '*' || t[0] == '/' || t[0] == '^');
}

Node *build(const string &line)
{
    stack<Node *> st;
    if (line.find(' ') != string::npos)
    {
        stringstream ss(line);
        string t;
        while (ss >> t)
        {
            if (!isOp(t))
                st.push(new Node(t));
            else
            {
                Node *r = st.top();
                st.pop();
                Node *l = st.top();
                st.pop();
                Node *op = new Node(t);
                op->left = l;
                op->right = r;
                st.push(op);
            }
        }
    }
    else
    {
        for (char c : line)
        {
            if (c == ' ' || c == '\t')
                continue;
            string t(1, c);
            if (!isOp(t))
                st.push(new Node(t));
            else
            {
                Node *r = st.top();
                st.pop();
                Node *l = st.top();
                st.pop();
                Node *op = new Node(t);
                op->left = l;
                op->right = r;
                st.push(op);
            }
        }
    }
    return st.empty() ? nullptr : st.top();
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
        cout << cur->val << ' ';
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
        cout << cur->val << ' ';
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
        cout << s2.top()->val << ' ';
        s2.pop();
    }
    cout << "\n";
}

int main()
{

    string line;
    getline(cin, line);
    if (line.empty())
        getline(cin, line);
    Node *root = build(line);
    inorderIt(root);
    preorderIt(root);
    postorderIt(root);
    return 0;
}


// Time Complexity: O(N)
// Space Complexity: O(H)

// Example Input:
// ab+c*
