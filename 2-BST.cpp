#include <iostream>
#include <queue>
#include <stack>
#include <cmath>
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

class BST{
public:
    Node *root;

    BST(){
        root = NULL;
    }

    Node* insert(Node *root, int val){
        if(root == NULL){
            return new Node(val);
        }

        if(val < root->data){
            root->left = insert(root->left, val);
        }else{
            root->right = insert(root->right, val);
        }

        return root;
    }

    Node* findMin(Node *root){
        while(root->left != NULL){
            root = root->left;
        }
        return root;
    }

    Node* deleteNode(Node *root, int val){
        if(root == NULL){
            return NULL;
        }

        if(val < root->data){
            root->left = deleteNode(root->left, val);
        }
        else if(val > root->data){
            root->right = deleteNode(root->right, val);
        }
        else{
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            else if(root->left == NULL){
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == NULL){
                Node *temp = root->left;
                delete root;
                return temp;
            }

            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
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

    bool search(Node *root, int val){
        if(root == NULL){
            return false;
        }

        if(root->data == val){
            return true;
        }

        if(val < root->data){
            return search(root->left, val);
        }else{
            return search(root->right, val);
        }
    }

    void bfs(Node *root){
        if(root == NULL){
            return;
        }

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node *temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if(temp->left != NULL){
                q.push(temp->left);
            }

            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }

    void recursiveInorder(Node *root){
        if(root != NULL){
            recursiveInorder(root->left);
            cout << root->data << " ";
            recursiveInorder(root->right);
        }
    }

    void iterativeInorder(Node *root){
        stack<Node*> s;
        Node *curr = root;

        while(curr != NULL || !s.empty()){
            while(curr != NULL){
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            s.pop();

            cout << curr->data << " ";

            curr = curr->right;
        }
    }

    int height(Node *root){
        if(root == NULL){
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if(leftHeight > rightHeight){
            return leftHeight + 1;
        }else{
            return rightHeight + 1;
        }
    }

    bool isBalanced(Node *root){
        if(root == NULL){
            return true;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if(abs(leftHeight - rightHeight) > 1){
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
    }
};

int main(){
    BST bt;
    int n, val, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values: ";
    for(int i = 0; i < n; i++){
        cin >> val;
        bt.root = bt.insert(bt.root, val);
    }

    cout << "\nBST Display: ";
    bt.display(bt.root);

    cout << "\nEnter value to search: ";
    cin >> key;

    if(bt.search(bt.root, key)){
        cout << "Node Found";
    }else{
        cout << "Node Not Found";
    }

    cout << "\nLevel Wise Print: ";
    bt.bfs(bt.root);

    cout << "\nRecursive Inorder: ";
    bt.recursiveInorder(bt.root);

    cout << "\nIterative Inorder: ";
    bt.iterativeInorder(bt.root);

    cout << "\nHeight of Tree: " << bt.height(bt.root);

    if(bt.isBalanced(bt.root)){
        cout << "\nTree is Height Balanced";
    }else{
        cout << "\nTree is Not Height Balanced";
    }

    cout << "\nEnter value to delete: ";
    cin >> key;

    bt.root = bt.deleteNode(bt.root, key);

    cout << "BST After Deletion: ";
    bt.display(bt.root);

    return 0;
}