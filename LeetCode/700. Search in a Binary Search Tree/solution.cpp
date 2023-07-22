#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* searchBST(TreeNode* root, int val) {

    if (root == nullptr)
        return nullptr;

    if (root->val == val)
        return root;

    return (root->val >= val) ? searchBST(root->left, val) : searchBST(root->right, val);

}

int main()
{
    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    std::cout << searchBST(root, 2) << "\n";
    std::cout << searchBST(root, 5) << "\n";
}
