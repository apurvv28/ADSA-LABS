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

void printLeaf(Node* root)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
    }

    printLeaf(root->left);
    printLeaf(root->right);
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

    cout << "\nLeaf Nodes: ";
    printLeaf(root);
}


// Time Complexity: O(N)
// Space Complexity: O(H)

// Example Input:
// Enter number of nodes: 5
// Enter root value: 1
// Enter left child: 2
// Enter left child: 4
// Enter right child: 5
// Enter right child: 3
