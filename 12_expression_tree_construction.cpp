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

void inorder(Node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);

    cout << root->data;

    inorder(root->right);
}

int main()
{
    string exp;
    cout << "Enter expression in postfix notation: ";
    cin >> exp;

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

    Node* root = st.top();

    cout << "\nInorder (Infix Expression): ";
    inorder(root);
}


// Time Complexity: O(N)
// Space Complexity: O(N)

// Example Input:
// Enter expression in postfix notation: ab+c*
