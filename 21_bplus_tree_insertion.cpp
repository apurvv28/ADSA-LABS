#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    bool leaf;

    vector<int> keys;
    vector<Node*> child;

    Node* next;

    Node(bool isLeaf)
    {
        leaf = isLeaf;
        next = NULL;
    }
};

class BPlusTree
{
    int order;

public:
    Node* root;

    BPlusTree(int m)
    {
        order = m;

        root = new Node(true);
    }

    int maxKeys()
    {
        return order - 1;
    }

    void insert(int key)
    {
        Node* current = root;

        vector<Node*> path;

        while (!current->leaf)
        {
            path.push_back(current);

            int i = 0;

            while (i < current->keys.size() &&
                   key >= current->keys[i])
            {
                i++;
            }

            current = current->child[i];
        }

        int i = 0;

        while (i < current->keys.size() &&
               key > current->keys[i])
        {
            i++;
        }

        current->keys.insert(current->keys.begin() + i, key);

        if (current->keys.size() <= maxKeys())
        {
            return;
        }

        int mid = current->keys.size() / 2;

        Node* newLeaf = new Node(true);

        for (int i = mid; i < current->keys.size(); i++)
        {
            newLeaf->keys.push_back(current->keys[i]);
        }

        current->keys.resize(mid);

        newLeaf->next = current->next;

        current->next = newLeaf;

        int promote = newLeaf->keys[0];

        if (path.empty())
        {
            Node* newRoot = new Node(false);

            newRoot->keys.push_back(promote);

            newRoot->child.push_back(current);
            newRoot->child.push_back(newLeaf);

            root = newRoot;

            return;
        }

        Node* parent = path.back();

        parent->keys.push_back(promote);

        parent->child.push_back(newLeaf);
    }

    void levelOrder()
    {
        queue<Node*> q;

        q.push(root);

        while (!q.empty())
        {
            int size = q.size();

            while (size--)
            {
                Node* current = q.front();
                q.pop();

                cout << "[";

                for (int x : current->keys)
                {
                    cout << x << " ";
                }

                cout << "] ";

                if (!current->leaf)
                {
                    for (Node* c : current->child)
                    {
                        q.push(c);
                    }
                }
            }

            cout << endl;
        }
    }
};

int main()
{
    int order, n;

    cout << "Enter order of B+ tree and number of elements: ";
    cin >> order >> n;

    BPlusTree tree(order);

    for (int i = 0; i < n; i++)
    {
        int value;
        cout << "Enter element " << (i+1) << ": ";
        cin >> value;

        tree.insert(value);
    }

    cout << "\nB+ Tree Structure (Level Order):" << endl;
    tree.levelOrder();
}


// Time Complexity: O(log N)
// Space Complexity: O(N)

// Example Input:
// Enter order of B+ tree and number of elements: 3 5
// Enter element 1: 10
// Enter element 2: 20
// Enter element 3: 5
// Enter element 4: 6
// Enter element 5: 12
