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

void get_leaf_vec(TreeNode* root, vector<int>& leaf_vals)
{
    if(root == nullptr)
        return;

    if(root->left == nullptr && root->right == nullptr)
        leaf_vals.push_back(root->val);
    
    get_leaf_vec(root->left, leaf_vals);
    get_leaf_vec(root->right, leaf_vals);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    
    vector<int> root1_leafs, root2_leafs;

    get_leaf_vec(root1, root1_leafs);
    get_leaf_vec(root2, root2_leafs);

    if(root1_leafs.size() != root2_leafs.size())
        return false;

    for (size_t i = 0; i < root1_leafs.size(); i++)
    {
        if(root1_leafs[i] != root2_leafs[i])
            return false;
    }
    return true;
}

int main()
{

    cout << "Test" << endl; 
    return 0; 

}