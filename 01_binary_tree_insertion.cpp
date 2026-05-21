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

// Function to insert node in Binary Tree
Node* insert(Node* root, int value)
{
    Node* newNode = new Node(value);

    if (root == NULL)
        return newNode;

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* current = q.front();
        q.pop();

        if (current->left == NULL)
        {
            current->left = newNode;
            return root;
        }
        else
        {
            q.push(current->left);
        }

        if (current->right == NULL)
        {
            current->right = newNode;
            return root;
        }
        else
        {
            q.push(current->right);
        }
    }

    return root;
}

// Function for Level Order Traversal
void levelOrder(Node* root)
{
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

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

int main()
{
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    Node* root = NULL;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> value;

        root = insert(root, value);
    }

    cout << "\nLevel Order Traversal: ";
    levelOrder(root);

    return 0;
}

/*
Time Complexity:
Insertion  -> O(N)
Traversal  -> O(N)

Example Input:
Enter number of nodes: 5
Enter value: 1
Enter value: 2
Enter value: 3
Enter value: 4
Enter value: 5

Output:
Level Order Traversal: 1 2 3 4 5
*/