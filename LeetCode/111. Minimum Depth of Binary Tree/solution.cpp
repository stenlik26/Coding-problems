#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void dfs(TreeNode* current, int current_depth, int& min_depth)
{
    if (current == NULL)
        return;

    if (current->left == NULL && current->right == NULL)
    {
        min_depth = (min_depth > current_depth) ? current_depth : min_depth;
    }

    dfs(current->left, current_depth + 1, min_depth);
    dfs(current->right, current_depth + 1, min_depth);

}

bool hasPathSum(TreeNode* root) {
    int min_depth = INT_MAX;
    dfs(root, 1, min_depth);
    return (min_depth != INT_MAX) ? min_depth : 0;
}

int main()
{
    struct TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(4);
    root->right->left = new TreeNode(4);
    std::cout << hasPathSum(root) << std::endl;
}
