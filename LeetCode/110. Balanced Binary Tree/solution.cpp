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

int get_height(TreeNode* current)
{
    if (current == nullptr)
        return 0;

    int height_left = get_height(current->left) + 1;
    int height_right = get_height(current->right) + 1;

    return (height_left > height_right) ? height_left : height_right;
}

bool isBalanced(TreeNode* root) {
    if (root == nullptr)
        return true;

    int h_left = get_height(root->left);
    int h_right = get_height(root->right);

    return abs(h_left - h_right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

int main()
{
    
    struct TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(29);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(2);
    root->right->right->right = new TreeNode(9);
    std::cout << isBalanced(root) << std::endl;
}
