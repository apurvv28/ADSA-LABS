#include <iostream>
using namespace std;

class BTreeNode{
public:
    int *keys;
    int t;
    BTreeNode **child;
    int n;
    bool leaf;

    BTreeNode(int temp, bool isLeaf){
        t = temp;
        leaf = isLeaf;

        keys = new int[2 * t - 1];
        child = new BTreeNode*[2 * t];

        n = 0;
    }

    void display(){
        int i;

        for(i = 0; i < n; i++){
            if(leaf == false){
                child[i]->display();
            }

            cout << keys[i] << " ";
        }

        if(leaf == false){
            child[i]->display();
        }
    }

    void splitChild(int i, BTreeNode *y){
        BTreeNode *z = new BTreeNode(y->t, y->leaf);

        z->n = t - 1;

        for(int j = 0; j < t - 1; j++){
            z->keys[j] = y->keys[j + t];
        }

        if(y->leaf == false){
            for(int j = 0; j < t; j++){
                z->child[j] = y->child[j + t];
            }
        }

        y->n = t - 1;

        for(int j = n; j >= i + 1; j--){
            child[j + 1] = child[j];
        }

        child[i + 1] = z;

        for(int j = n - 1; j >= i; j--){
            keys[j + 1] = keys[j];
        }

        keys[i] = y->keys[t - 1];

        n++;

        cout << "\nNode Split";
        cout << "\nPromoted Key: " << keys[i];
    }

    void insertNonFull(int k){
        int i = n - 1;

        if(leaf == true){
            while(i >= 0 && keys[i] > k){
                keys[i + 1] = keys[i];
                i--;
            }

            keys[i + 1] = k;
            n++;
        }
        else{
            while(i >= 0 && keys[i] > k){
                i--;
            }

            if(child[i + 1]->n == 2 * t - 1){
                splitChild(i + 1, child[i + 1]);

                if(keys[i + 1] < k){
                    i++;
                }
            }

            child[i + 1]->insertNonFull(k);
        }
    }
};

class BTree{
public:
    BTreeNode *root;
    int t;

    BTree(int temp){
        root = NULL;
        t = temp;
    }

    void insert(int k){
        if(root == NULL){
            root = new BTreeNode(t, true);
            root->keys[0] = k;
            root->n = 1;
        }
        else{
            if(root->n == 2 * t - 1){
                BTreeNode *s = new BTreeNode(t, false);

                s->child[0] = root;

                s->splitChild(0, root);

                int i = 0;

                if(s->keys[0] < k){
                    i++;
                }

                s->child[i]->insertNonFull(k);

                root = s;
            }
            else{
                root->insertNonFull(k);
            }
        }
    }

    void display(){
        if(root != NULL){
            root->display();
        }
    }
};

int main(){
    int t, n, val;

    cout << "Enter order of B-Tree: ";
    cin >> t;

    BTree bt(t);

    cout << "Enter number of keys: ";
    cin >> n;

    cout << "Enter keys: ";
    for(int i = 0; i < n; i++){
        cin >> val;
        bt.insert(val);
    }

    cout << "\nB-Tree Structure: ";
    bt.display();

    return 0;
}