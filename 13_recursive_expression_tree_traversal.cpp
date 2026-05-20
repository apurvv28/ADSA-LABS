#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    char data;
    Node* left;
    Node* right;

    Node(char value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

Node* buildTree(string exp)
{
    stack<Node*> st;

    for (char ch : exp)
    {
        if (!isOperator(ch))
        {
            st.push(new Node(ch));
        }

        else
        {
            Node* right = st.top();
            st.pop();

            Node* left = st.top();
            st.pop();

            Node* op = new Node(ch);

            op->left = left;
            op->right = right;

            st.push(op);
        }
    }

    return st.top();
}

void inorder(Node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    string exp;
    cout << "Enter expression in postfix notation: ";
    cin >> exp;

    Node* root = buildTree(exp);

    cout << "\nInorder: ";
    inorder(root);
    cout << endl;

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
}


// Time Complexity: O(N)
// Space Complexity: O(H)

// Example Input:
// Enter expression in postfix notation: ab+c*
