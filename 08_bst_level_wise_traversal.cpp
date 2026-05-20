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

Node* insert(Node* root, int value)
{
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    Node* root = NULL;

    for (int i = 0; i < n; i++)
    {
        int value;
        cout << "Enter node " << (i+1) << ": ";
        cin >> value;

        root = insert(root, value);
    }

    queue<Node*> q;
    q.push(root);

    cout << "\nLevel Order Traversal:" << endl;
    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            Node* current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left)
                q.push(current->left);

            if (current->right)
                q.push(current->right);
        }

        cout << endl;
    }
}


// Time Complexity: O(N)
// Space Complexity: O(W) where W is max width

// Example Input:
// Enter number of nodes: 5
// Enter node 1: 5
// Enter node 2: 3
// Enter node 3: 7
// Enter node 4: 1
// Enter node 5: 9
