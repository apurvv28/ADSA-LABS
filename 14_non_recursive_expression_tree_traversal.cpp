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
    stack<Node*> st;
    Node* current = root;

    while (current != NULL || !st.empty())
    {
        while (current != NULL)
        {
            st.push(current);
            current = current->left;
        }

        current = st.top();
        st.pop();

        cout << current->data << " ";

        current = current->right;
    }

    cout << endl;
}

void preorder(Node* root)
{
    stack<Node*> st;
    st.push(root);

    while (!st.empty())
    {
        Node* current = st.top();
        st.pop();

        cout << current->data << " ";

        if (current->right)
            st.push(current->right);

        if (current->left)
            st.push(current->left);
    }

    cout << endl;
}

int main()
{
    string exp;
    cout << "Enter expression in postfix notation: ";
    cin >> exp;

    Node* root = buildTree(exp);

    cout << "\nInorder: ";
    inorder(root);

    cout << "Preorder: ";
    preorder(root);
}


// Time Complexity: O(N)
// Space Complexity: O(H)

// Example Input:
// Enter expression in postfix notation: ab+c*
