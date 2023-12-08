#include<iostream>
#include <string>
#include<vector>

using namespace std;

struct TreeNode
 {

    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};

string tree2str(TreeNode* root) {
    if(root == nullptr)
        return "()";

    if(root->left == nullptr && root->right == nullptr)
        return to_string(root->val);

    if(root->left == nullptr && root->right != nullptr)
        return to_string(root->val) + tree2str(root->left) + "(" + tree2str(root->right) + ")";
    
    if(root->left != nullptr && root->right == nullptr)
        return to_string(root->val) + "(" + tree2str(root->left) + ")";
    
    return to_string(root->val) + "(" + tree2str(root->left) + ")" + + "(" + tree2str(root->right) + ")";
}

int main()
{


 TreeNode* root = 
    new TreeNode(1, 
        new TreeNode(2, 
            new TreeNode(4, 
                nullptr,
                nullptr),
            nullptr),
        new TreeNode(3,
            nullptr,
            nullptr));

    
 cout << tree2str(root) << endl; 
 return 0; 

}
