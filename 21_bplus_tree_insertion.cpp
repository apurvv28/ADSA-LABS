#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    bool leaf;
    vector<int> keys;
    vector<Node *> child;
    Node *next;
    Node(bool isLeaf) : leaf(isLeaf), next(nullptr) {}
};

struct BPlusTree
{
    int m;
    Node *root;
    BPlusTree(int order) : m(order), root(new Node(true)) {}

    int maxKeys() const { return m - 1; }
    int minKeysLeaf() const { return (maxKeys() + 1) / 2; }
    int minKeysInternal() const { return (maxKeys()) / 2; }

    Node *findLeaf(int key)
    {
        Node *cur = root;
        while (!cur->leaf)
        {
            int i = 0;
            while (i < (int)cur->keys.size() && key >= cur->keys[i])
                i++;
            cur = cur->child[i];
        }
        return cur;
    }

    void insertInternal(int key, Node *left, Node *right, vector<Node *> &path)
    {
        if (path.empty())
        {
            Node *nr = new Node(false);
            nr->keys.push_back(key);
            nr->child.push_back(left);
            nr->child.push_back(right);
            root = nr;
            return;
        }

        Node *parent = path.back();
        path.pop_back();

        int pos = 0;
        while (pos < (int)parent->child.size() && parent->child[pos] != left)
            pos++;
        parent->keys.insert(parent->keys.begin() + pos, key);
        parent->child.insert(parent->child.begin() + pos + 1, right);

        if ((int)parent->keys.size() <= maxKeys())
            return;

        int midIdx = (int)parent->keys.size() / 2;
        int upKey = parent->keys[midIdx];

        Node *newInternal = new Node(false);
        newInternal->keys.assign(parent->keys.begin() + midIdx + 1, parent->keys.end());
        newInternal->child.assign(parent->child.begin() + midIdx + 1, parent->child.end());

        parent->keys.resize(midIdx);
        parent->child.resize(midIdx + 1);

        insertInternal(upKey, parent, newInternal, path);
    }

    void insert(int key)
    {
        vector<Node *> path;
        Node *cur = root;
        while (!cur->leaf)
        {
            path.push_back(cur);
            int i = 0;
            while (i < (int)cur->keys.size() && key >= cur->keys[i])
                i++;
            cur = cur->child[i];
        }

        int i = 0;
        while (i < (int)cur->keys.size() && cur->keys[i] < key)
            i++;
        cur->keys.insert(cur->keys.begin() + i, key);

        if ((int)cur->keys.size() <= maxKeys())
            return;

        int split = (int)cur->keys.size() / 2;
        Node *newLeaf = new Node(true);
        newLeaf->keys.assign(cur->keys.begin() + split, cur->keys.end());
        cur->keys.resize(split);

        newLeaf->next = cur->next;
        cur->next = newLeaf;

        int promote = newLeaf->keys[0];
        insertInternal(promote, cur, newLeaf, path);
    }

    void printLevels()
    {
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int sz = (int)q.size();
            while (sz--)
            {
                Node *n = q.front();
                q.pop();
                cout << "[";
                for (int k : n->keys)
                    cout << k << ' ';
                cout << "] ";
                if (!n->leaf)
                    for (auto *c : n->child)
                        q.push(c);
            }
            cout << "\n";
        }
    }
};

int main()
{
    int order, n;
    cin >> order >> n;
    if (order < 3)
        order = 3;
    BPlusTree t(order);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        t.insert(x);
    }
    t.printLevels();
    return 0;
}


// Time Complexity: O(log N)
// Space Complexity: O(N)

// Example Input:
// 3
// 5
// 10 20 5 6 12
