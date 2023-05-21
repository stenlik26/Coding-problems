#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void preorder(TreeNode* node, vector<int>* vals)
{
    if (node == nullptr)
        return;

    vals->push_back(node->val);

    preorder(node->left, vals);

    preorder(node->right, vals);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> vals;
    preorder(root, &vals);
    return vals;
}

int main()
{
    TreeNode* root = new TreeNode(25);

    root->left = new TreeNode(15);
    root->right = new TreeNode(50);

    root->left->left = new TreeNode(10);
    root->left->right = new TreeNode(22);

    root->right->left = new TreeNode(35);
    root->right->right = new TreeNode(70);

    vector<int> vals = preorderTraversal(root);

    for (auto i = vals.begin(); i < vals.end(); i++)
    {
        cout << *i << " ";
    }

    cout << endl;
}