#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    vector<int> keys;
    vector<Node*> child;
    bool leaf;

    Node(bool isLeaf)
    {
        leaf = isLeaf;
    }
};

class BTree
{
    int t;

public:
    Node* root;

    BTree(int degree)
    {
        t = degree;
        root = NULL;
    }

    void split(Node* parent, int index)
    {
        Node* fullNode = parent->child[index];

        Node* newNode = new Node(fullNode->leaf);

        int middle = fullNode->keys[t - 1];

        for (int i = t; i < fullNode->keys.size(); i++)
        {
            newNode->keys.push_back(fullNode->keys[i]);
        }

        if (!fullNode->leaf)
        {
            for (int i = t; i < fullNode->child.size(); i++)
            {
                newNode->child.push_back(fullNode->child[i]);
            }

            fullNode->child.resize(t);
        }

        fullNode->keys.resize(t - 1);

        parent->keys.insert(parent->keys.begin() + index, middle);

        parent->child.insert(parent->child.begin() + index + 1, newNode);
    }

    void insertNonFull(Node* node, int key)
    {
        int i = node->keys.size() - 1;

        if (node->leaf)
        {
            node->keys.push_back(0);

            while (i >= 0 && key < node->keys[i])
            {
                node->keys[i + 1] = node->keys[i];
                i--;
            }

            node->keys[i + 1] = key;
        }

        else
        {
            while (i >= 0 && key < node->keys[i])
            {
                i--;
            }

            i++;

            if (node->child[i]->keys.size() == 2 * t - 1)
            {
                split(node, i);

                if (key > node->keys[i])
                {
                    i++;
                }
            }

            insertNonFull(node->child[i], key);
        }
    }

    void insert(int key)
    {
        if (root == NULL)
        {
            root = new Node(true);

            root->keys.push_back(key);

            return;
        }

        if (root->keys.size() == 2 * t - 1)
        {
            Node* newRoot = new Node(false);

            newRoot->child.push_back(root);

            split(newRoot, 0);

            int i = 0;

            if (key > newRoot->keys[0])
            {
                i++;
            }

            insertNonFull(newRoot->child[i], key);

            root = newRoot;
        }

        else
        {
            insertNonFull(root, key);
        }
    }

    void print(Node* node)
    {
        if (node == NULL)
            return;

        for (int x : node->keys)
        {
            cout << x << " ";
        }

        cout << endl;

        for (Node* c : node->child)
        {
            print(c);
        }
    }
};

int main()
{
    int degree, n;

    cout << "Enter degree of B-tree and number of elements: ";
    cin >> degree >> n;

    BTree tree(degree);

    for (int i = 0; i < n; i++)
    {
        int value;
        cout << "Enter element " << (i+1) << ": ";
        cin >> value;

        tree.insert(value);
    }

    cout << "\nB-Tree Structure (Level Order):" << endl;
    tree.print(tree.root);
}


// Time Complexity: O(log N)
// Space Complexity: O(N)

// Example Input:
// Enter degree of B-tree and number of elements: 3 5
// Enter element 1: 10
// Enter element 2: 20
// Enter element 3: 5
// Enter element 4: 6
// Enter element 5: 12
