#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool dfs(Node* root,Node* subRoot){
    if(root == nullptr && subRoot == nullptr){
        return true;
    }
    else if(root == nullptr || subRoot == nullptr || root->data != subRoot->data){
        return false;
    }
    if(root->data == subRoot->data){
        return dfs(root->left,subRoot->left) && dfs(root->right,subRoot->right);
    }
    return dfs(root->left, subRoot) || dfs(root->right, subRoot);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Node root(1);
    root.left = new Node(2);
    root.right = new Node(3);
    root.left->left = new Node(4);
    root.left->right = new Node(5);    
    root.right->left = new Node(6);
    root.right->right = new Node(7);

    Node subRoot(2);
    subRoot.left = new Node(4);
    subRoot.right = new Node(5);

    if(dfs(&root, &subRoot)){
        cout << "Subtree exists" << endl;
    } else {
        cout << "Subtree does not exist" << endl;
    }
    return 0;
}