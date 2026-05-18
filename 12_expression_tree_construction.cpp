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

string inorder(Node *r)
{
    if (!r)
        return "";
    if (!isOp(r->val))
        return r->val;
    return "(" + inorder(r->left) + r->val + inorder(r->right) + ")";
}

int main()
{

    string line;
    getline(cin, line);
    if (line.empty())
        getline(cin, line);
    if (line.empty())
        return 0;

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

    Node *root = st.empty() ? nullptr : st.top();
    cout << inorder(root) << "\n";
    return 0;
}


// Time Complexity: O(N)
// Space Complexity: O(N)

// Example Input:
// ab+c*
