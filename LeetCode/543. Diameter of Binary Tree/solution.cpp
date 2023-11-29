#include <iostream>
#include <algorithm>
#include <initializer_list>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

const int max_lenght_to_root (TreeNode* root)
{
    if (root == nullptr)
        return -1;

    return 1 + std::max(max_lenght_to_root(root->left), max_lenght_to_root(root->right));
}

int diameterOfBinaryTree(TreeNode* root) {
    if (root == nullptr)
        return 0;
    return std::max(
        {
        (max_lenght_to_root(root->left) + max_lenght_to_root(root->right) + 2),
        (diameterOfBinaryTree(root->left)),
        (diameterOfBinaryTree(root->right))
        }
    );     
}

int main()
{
    TreeNode* root = 
    new TreeNode(1,
        new TreeNode(2, 
            new TreeNode(4, nullptr, nullptr),
            new TreeNode(5, nullptr, nullptr)),
       nullptr
    );

    TreeNode* root2 = 
    new TreeNode(1,
        new TreeNode(2, nullptr, nullptr), nullptr
    );

    cout << "test"<<endl;

}