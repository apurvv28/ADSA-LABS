#include <iostream>
using namespace std;
class Node{
public:
    int data, height;
    Node *left, *right;
    Node(int val){
        data = val;
        height = 1;
        left = right = NULL;
    }
};
class AVLTree{
public:
    Node *root;
    AVLTree(){
        root = NULL;
    }
    int getHeight(Node *root){
        if(root == NULL){
            return 0;
        }
        return root->height;
    }
    int getBalance(Node *root){
        if(root == NULL){
            return 0;
        }
        return getHeight(root->left) - getHeight(root->right);
    }
    int max(int a, int b){
        if(a > b){
            return a;
        }else{
            return b;
        }
    }
    Node* rightRotate(Node *y){
        Node *x = y->left;
        Node *t2 = x->right;
        x->right = y;
        y->left = t2;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        return x;
    }
    Node* leftRotate(Node *x){
        Node *y = x->right;
        Node *t2 = y->left;
        y->left = x;
        x->right = t2;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        return y;
    }
    Node* insert(Node *root, int val){
        if(root == NULL){
            return new Node(val);
        }
        if(val < root->data){
            root->left = insert(root->left, val);
        }
        else if(val > root->data){
            root->right = insert(root->right, val);
        }
        else{
            return root;
        }
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
        int balance = getBalance(root);
        if(balance > 1 && val < root->left->data){
            cout << "\nLL Rotation Performed";
            return rightRotate(root);
        }
        if(balance < -1 && val > root->right->data){
            cout << "\nRR Rotation Performed";
            return leftRotate(root);
        }
        if(balance > 1 && val > root->left->data){
            cout << "\nLR Rotation Performed";
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if(balance < -1 && val < root->right->data){
            cout << "\nRL Rotation Performed";
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }
    Node* minValue(Node *root){
        Node *temp = root;
        while(temp->left != NULL){
            temp = temp->left;
        }
        return temp;
    }
    Node* deleteNode(Node *root, int val){
        if(root == NULL){
            return root;
        }
        if(val < root->data){
            root->left = deleteNode(root->left, val);
        }
        else if(val > root->data){
            root->right = deleteNode(root->right, val);
        }
        else{
            if(root->left == NULL || root->right == NULL){
                Node *temp;
                if(root->left != NULL){
                    temp = root->left;
                }else{
                    temp = root->right;
                }
                if(temp == NULL){
                    temp = root;
                    root = NULL;
                }else{
                    *root = *temp;
                }
                delete temp;
            }
            else{
                Node *temp = minValue(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }
        if(root == NULL){
            return root;
        }
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
        int balance = getBalance(root);
        if(balance > 1 && getBalance(root->left) >= 0){
            cout << "\nLL Rotation Performed";
            return rightRotate(root);
        }
        if(balance > 1 && getBalance(root->left) < 0){
            cout << "\nLR Rotation Performed";
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if(balance < -1 && getBalance(root->right) <= 0){
            cout << "\nRR Rotation Performed";
            return leftRotate(root);
        }
        if(balance < -1 && getBalance(root->right) > 0){
            cout << "\nRL Rotation Performed";
            root->right = rightRotate(root->right);
            return leftRotate(root);
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
};
int main(){
    AVLTree at;
    int n, val, del;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter node values: ";
    for(int i = 0; i < n; i++){
        cin >> val;
        at.root = at.insert(at.root, val);
    }
    cout << "\nAVL Tree: ";
    at.display(at.root);
    cout << "\nEnter node to delete: ";
    cin >> del;
    at.root = at.deleteNode(at.root, del);
    cout << "\nAVL Tree After Deletion: ";
    at.display(at.root);
    return 0;
}