#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void postorder(TreeNode* node, vector<int>* vals)
{
    if (node == nullptr)
        return;

    postorder(node->left, vals);

    postorder(node->right, vals);

    vals->push_back(node->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> vals;
    postorder(root, &vals);
    return vals;
}

int main()
{
    TreeNode* root = new TreeNode(25);

    root->left = new TreeNode(15);
    root->right = new TreeNode(50);

    root->left->left = new TreeNode(10);
    root->left->right = new TreeNode(22);

    root->right->left = new TreeNode(35);
    root->right->right = new TreeNode(70);

    vector<int> vals = postorderTraversal(root);

    for (auto i = vals.begin(); i < vals.end(); i++)
    {
        cout << *i << " ";
    }

    cout << endl;
}