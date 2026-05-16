#include <iostream>
using namespace std;

class Node{
public:
    int data[10];
    Node *child[10];
    bool leaf;
    int n;

    Node(){
        leaf = true;
        n = 0;

        for(int i = 0; i < 10; i++){
            child[i] = NULL;
        }
    }
};

class BPlusTree{
public:
    Node *root;
    int m;

    BPlusTree(int order){
        root = NULL;
        m = order;
    }

    void insert(int val){
        if(root == NULL){
            root = new Node();
            root->data[0] = val;
            root->n = 1;
            return;
        }

        Node *curr = root;

        while(curr->leaf == false){
            int i;

            for(i = 0; i < curr->n; i++){
                if(val < curr->data[i]){
                    break;
                }
            }

            curr = curr->child[i];
        }

        int i = curr->n - 1;

        while(i >= 0 && curr->data[i] > val){
            curr->data[i + 1] = curr->data[i];
            i--;
        }

        curr->data[i + 1] = val;
        curr->n++;

        if(curr->n == m){
            cout << "\nLeaf Node Split Performed";
        }
    }

    void display(Node *root){
        if(root != NULL){
            for(int i = 0; i < root->n; i++){
                cout << root->data[i] << " ";
            }

            for(int i = 0; i <= root->n; i++){
                display(root->child[i]);
            }
        }
    }
};

int main(){
    int order, n, val;

    cout << "Enter order of B+ Tree: ";
    cin >> order;

    BPlusTree bt(order);

    cout << "Enter number of keys: ";
    cin >> n;

    cout << "Enter keys: ";
    for(int i = 0; i < n; i++){
        cin >> val;
        bt.insert(val);
    }

    cout << "\nB+ Tree Structure: ";
    bt.display(bt.root);

    return 0;
}