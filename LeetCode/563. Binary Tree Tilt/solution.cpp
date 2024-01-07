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

int sumTree(TreeNode* root)
{
    if(root == nullptr)
        return 0;

    return root->val + sumTree(root->left) + sumTree(root->right);
}

void findTiltRec(TreeNode* current)
{
    if(current == nullptr)
        return;

    current->val = abs(sumTree(current->left) - sumTree(current->right));

    findTiltRec(current->left);
    findTiltRec(current->right); 
}

int findTilt(TreeNode* root) {
    findTiltRec(root);

    return sumTree(root);
}

int main()
{

    TreeNode* root = new TreeNode(
        4,
        new TreeNode(2, new TreeNode(3), new TreeNode(5)),
        new TreeNode(9, nullptr, new TreeNode(7))
    );

    cout << findTilt(root)<<endl;
    return 0; 

}