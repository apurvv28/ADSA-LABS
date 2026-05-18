#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

int main() {
    int n;
    cin >> n;
    if(n <= 0){
        return 0;
    } 
    int x;
    cin >> x;
    Node* root = new Node(x);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while (i < n){
        Node* cur = q.front();
        q.pop();
        if (i < n){
            cin >> x;
            cur->left = new Node(x);
            q.push(cur->left);
            i++;
        }
        if (i < n){
            cin >> x;
            cur->right = new Node(x);
            q.push(cur->right);
            i++;
        }
    }
    queue<Node*> out;
    out.push(root);
    while (!out.empty()) {
        Node* cur = out.front();
        out.pop();
        cout << cur->data << ' ';
        if (cur->left) out.push(cur->left);
        if (cur->right) out.push(cur->right);
    }
    cout << endl;
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(W) where W is maximum width

// Example Input:
// 5
// 1 2 3 4 5
