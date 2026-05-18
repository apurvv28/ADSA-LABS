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

string inorder(Node *r)
{
    if (!r)
        return "";
    if (!isOp(r->val))
        return r->val;
    return "(" + inorder(r->left) + r->val + inorder(r->right) + ")";
}

void preorder(Node *r)
{
    if (!r)
        return;
    cout << r->val << ' ';
    preorder(r->left);
    preorder(r->right);
}
void postorder(Node *r)
{
    if (!r)
        return;
    postorder(r->left);
    postorder(r->right);
    cout << r->val << ' ';
}

int main()
{

    string line;
    getline(cin, line);
    if (line.empty())
        getline(cin, line);
    Node *root = build(line);
    cout << inorder(root) << "\n";
    preorder(root);
    cout << "\n";
    postorder(root);
    cout << "\n";
    return 0;
}


// Time Complexity: O(N)
// Space Complexity: O(H)

// Example Input:
// ab+c*
