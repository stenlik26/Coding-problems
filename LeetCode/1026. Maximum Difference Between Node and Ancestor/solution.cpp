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

int max_ansest_diff(TreeNode* root, int a_min, int a_max)
{
    if(!root)
    {
        return max - min;
    }

    a_max = max(a_max, root->val);
    a_min = min(a_min, root->val);

    int left = max_ansest_diff(root->left, a_min, a_max);
    int right = max_ansest_diff(root->right, a_min, a_max);

    return max(left,right);
}

int maxAncestorDiff(TreeNode* root) {
    if(!root)
        return 0;

    return max_ansest_diff(root, root->val, root->val);;
}

int main()
{

    cout << "Test" << endl; 
    return 0; 

}