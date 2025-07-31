// Traversal in Order of Node Height
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};

void levelwalk(TreeNode *root)
{
    if (root == nullptr)
        return;
    queue<pair<TreeNode *, int>> Q;
    stack<int> s, l;
    Q.push({root, 0});

    while (!Q.empty())
    {
        auto [node, level] = Q.front();
        Q.pop();
        s.push(node->value);
        l.push(level);

        if (node->left)
            Q.push({node->left, level + 1});
        if (node->right)
            Q.push({node->right, level + 1});
    }

    while (!s.empty())
    {
        cout << s.top() << " " << l.top() << endl;
        s.pop();
        l.pop();
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Level Walk: ";
    levelwalk(root);

    return 0;
}
