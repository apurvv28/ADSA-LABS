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

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n == 0)
        return 0;

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

        cout << "Enter left child: ";
        cin >> value;
        current->left = new Node(value);
        q.push(current->left);
        count++;

        if (count < n)
        {
            cout << "Enter right child: ";
            cin >> value;
            current->right = new Node(value);
            q.push(current->right);
            count++;
        }
    }

    q.push(root);

    cout << "\nLevel Order Traversal: ";
    while (!q.empty())
    {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left)
            q.push(current->left);

        if (current->right)
            q.push(current->right);
    }
}

// Time Complexity: O(N)
// Space Complexity: O(W) where W is maximum width

// Example Input:
// Enter number of nodes: 5
// Enter root value: 1
// Enter left child: 2
// Enter left child: 4
// Enter right child: 5
// Enter right child: 3
