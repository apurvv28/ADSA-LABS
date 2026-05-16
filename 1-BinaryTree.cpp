#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};
class BinaryTree{
public:
    Node *root;
    BinaryTree(){
        root = NULL;
    }
    Node* insert(Node *root, int val){
        if (root == NULL){
            return new Node(val);
        }
        if (val < root->data){
            root->left = insert(root->left, val);
        }else{
            root->right = insert(root->right, val);
        }
        return root;
    }
    void display(Node *root){
        if(root != NULL){
            display(root->left);
            cout << root->data << " ";
            display(root->right);
        }
    }
    int depth(Node *root){
        if (root == NULL){
            return 0;
        }
        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);
        if (leftDepth > rightDepth){
            return leftDepth + 1;
        }
        else{
            return rightDepth + 1;
        }
    }
    void leafNodes(Node *root){
        if (root != NULL){
            if (root->left == NULL && root->right == NULL){
                cout << root->data << " ";
            }
            leafNodes(root->left);
            leafNodes(root->right);
        }
    }
    Node* copyTree(Node *root){
        if (root == NULL){
            return NULL;
        }
        Node *newNode = new Node(root->data);
        newNode->left = copyTree(root->left);
        newNode->right = copyTree(root->right);
        return newNode;
    }
};

int main(){
    BinaryTree bt;
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter node values: ";
    for (int i = 0; i < n; i++){
        cin >> val;
        bt.root = bt.insert(bt.root, val);
    }
    cout << "\nTree Display: ";
    bt.display(bt.root);
    cout << "\nDepth of Tree: " << bt.depth(bt.root);
    cout << "\nLeaf Nodes: ";
    bt.leafNodes(bt.root);
    BinaryTree copyBT;
    copyBT.root = bt.copyTree(bt.root);
    cout << "\nCopied Tree: ";
    copyBT.display(copyBT.root);
    return 0;
}