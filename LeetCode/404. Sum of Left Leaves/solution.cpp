#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};

int sum_util(TreeNode* root, bool is_left)
{
    if (root->left == nullptr && root->right == nullptr)
        return is_left ? root->val : 0;

    int sum = 0;

    if (root->left != nullptr)
        sum += sum_util(root->left, true);
    if (root->right != nullptr)
        sum += sum_util(root->right, false);

    return sum;
}

int sumOfLeftLeaves(TreeNode* root) 
{
    return sum_util(root, false);
}
int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    std::cout << sumOfLeftLeaves(root) << std::endl;
}
