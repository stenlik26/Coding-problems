#include <iostream>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool dfs(TreeNode* current, int targetSum, int currentSum)
{
    if (current == NULL)
        return false;

    if ((currentSum + current->val == targetSum) && (current->left == NULL && current->right == NULL))
        return true;

    bool dfs_left = dfs(current->left, targetSum, currentSum + current->val);
    bool dfs_right = dfs(current->right, targetSum, currentSum + current->val);
    return (dfs_left) ||
        (dfs_right);
}

bool hasPathSum(TreeNode* root, int targetSum) {
    return dfs(root, targetSum, 0);
}

int main()
{
    struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    std::cout << hasPathSum(root, 4) << " " << hasPathSum(root, 7) << 
        " " << hasPathSum(root, 3) << std::endl;
}
