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



int maxDepth(TreeNode* root) {
    
    if (root == NULL)
        return 0;

    int left_dep = maxDepth(root->left);
    int right_dep = maxDepth(root->right);

    return (left_dep > right_dep) ? left_dep + 1 : right_dep + 1;

}

int main()
{
    struct TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(3);
    root->right = new TreeNode(29);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(4);
    std::cout << maxDepth(root) << std::endl;
}
