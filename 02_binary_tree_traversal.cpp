#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

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
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int value;
    cout << "Enter root value: ";
    cin >> value;

    Node* root = new Node(value);

    queue<Node*> q;
    q.push(root);

    int count = 1;

    while (count < n)
    {
        Node* current = q.front();
        q.pop();

        cin >> value;
        current->left = new Node(value);
        q.push(current->left);
        count++;

        if (count < n)
        {
            cin >> value;
            current->right = new Node(value);
            q.push(current->right);
            count++;
        }
    }

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
// Space Complexity: O(H) where H is height

// Example Input:
// Enter number of nodes: 5
// Enter root value: 1
// Enter left child: 2
// Enter left child: 4
// Enter right child: 5
// Enter right child: 3
