#include <bits/stdc++.h>
using namespace std;
#define int long long
map<int, vector<int>> adj;
vector<int> ans;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void topView(Node *node, int key)
{
    if (node == nullptr)
        return;
    if (node->left != nullptr)
    {
        adj[key - 1].push_back(node->left->data);
    }
    if (node->right != nullptr)
    {
        adj[key + 1].push_back(node->right->data);
    }
    topView(node->left, key - 1);
    topView(node->right, key + 1);
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->right = new Node(6);
    root->right->right = new Node(5);
    root->right->right->left = new Node(7);
    // Expected top view: 4 2 1 3 5

    adj[0].push_back(root->data);
    topView(root, 0);

    for (auto &it : adj)
    {
        if (!it.second.empty())
        {
            ans.push_back(it.second[0]);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}