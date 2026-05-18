#include <iostream>
#include <vector>
using namespace std;

struct BTreeNode
{
    int t;
    bool leaf;
    vector<int> keys;
    vector<BTreeNode *> c;
    BTreeNode(int t_, bool leaf_) : t(t_), leaf(leaf_) {}
};

struct BTree
{
    BTreeNode *root;
    int t;
    BTree(int t_) : root(nullptr), t(t_) {}

    void splitChild(BTreeNode *x, int i)
    {
        BTreeNode *y = x->c[i];
        BTreeNode *z = new BTreeNode(t, y->leaf);

        int mid = y->keys[t - 1];
        for (int j = 0; j < t - 1; j++)
            z->keys.push_back(y->keys[j + t]);
        y->keys.resize(t - 1);

        if (!y->leaf)
        {
            for (int j = 0; j < t; j++)
                z->c.push_back(y->c[j + t]);
            y->c.resize(t);
        }

        x->c.insert(x->c.begin() + i + 1, z);
        x->keys.insert(x->keys.begin() + i, mid);
    }

    void insertNonFull(BTreeNode *x, int k)
    {
        int i = (int)x->keys.size() - 1;
        if (x->leaf)
        {
            x->keys.push_back(0);
            while (i >= 0 && k < x->keys[i])
            {
                x->keys[i + 1] = x->keys[i];
                i--;
            }
            x->keys[i + 1] = k;
        }
        else
        {
            while (i >= 0 && k < x->keys[i])
                i--;
            i++;
            if ((int)x->c[i]->keys.size() == 2 * t - 1)
            {
                splitChild(x, i);
                if (k > x->keys[i])
                    i++;
            }
            insertNonFull(x->c[i], k);
        }
    }

    void insert(int k)
    {
        if (!root)
        {
            root = new BTreeNode(t, true);
            root->keys.push_back(k);
            return;
        }
        if ((int)root->keys.size() == 2 * t - 1)
        {
            BTreeNode *s = new BTreeNode(t, false);
            s->c.push_back(root);
            splitChild(s, 0);
            int i = (k > s->keys[0]) ? 1 : 0;
            insertNonFull(s->c[i], k);
            root = s;
        }
        else
        {
            insertNonFull(root, k);
        }
    }

    void print(BTreeNode *x, int lvl)
    {
        if (!x)
            return;
        for (int i = 0; i < lvl; i++)
            cout << "  ";
        for (int k : x->keys)
            cout << k << ' ';
        cout << "\n";
        for (auto *ch : x->c)
            print(ch, lvl + 1);
    }
};

int main()
{
    int t, n;
    cin >> t >> n;
    if (t < 2)
        t = 2;
    BTree bt(t);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        bt.insert(x);
    }
    bt.print(bt.root, 0);
    return 0;
}


// Time Complexity: O(log N)
// Space Complexity: O(N)

// Example Input:
// 3
// 5
// 10 20 5 6 12
