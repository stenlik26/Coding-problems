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


int rangeSumBST(TreeNode* root, int low, int high) {
    if(root == nullptr)
        return 0;

    if(root->val < low)
        return rangeSumBST(root->right, low, high);
    
    if(root->val > high)
        return rangeSumBST(root->left, low, high);

    return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}

int main()
{
    TreeNode* root = new TreeNode(
        10,
        new TreeNode(5, new TreeNode(3), new TreeNode(7)),
        new TreeNode(15, nullptr, new TreeNode(18))
    );


    cout << "Test" << endl; 
    return 0; 

}