#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void inorder(TreeNode* node)
{
    if (node == nullptr)
        return;

    inorder(node->left);

    cout << node->val << " ";

    inorder(node->right);
}

void invert(TreeNode* node)
{
    if (node == nullptr)
        return;

    swap(node->left, node->right);

    invert(node->left);
    invert(node->right);
}

TreeNode* invertTree(TreeNode* root) {
    invert(root);
    return root;
}



int main()
{

    struct TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    inorder(root);
    cout << endl;

    invert(root);

    inorder(root);
    cout << endl;
}
