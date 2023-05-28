#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};

void bfs(TreeNode* current, string current_string, vector<string>& cont)
{
    if (current->left == nullptr && current->right == nullptr)
    {
        current_string += to_string(current->val);
        cont.push_back(current_string);
        return;
    }

    current_string += to_string(current->val) + "->";

    if (current->left != nullptr)
        bfs(current->left, current_string, cont);

    if (current->right != nullptr)
        bfs(current->right, current_string, cont);

}

vector<string> binaryTreePaths(TreeNode* root) {

    vector<string> res;

    bfs(root, "", res);
}

int main()
{
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);

    vector<string>s = binaryTreePaths(root);

    for (size_t i = 0; i < s.size(); i++)
    {
        cout << s[i] << endl;
    }
}
