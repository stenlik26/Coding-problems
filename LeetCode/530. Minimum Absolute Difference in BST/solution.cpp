/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

int abs_diff(TreeNode* node1, TreeNode* node2)
{
    if (node1 == nullptr || node2 == nullptr)
        return INT_MAX;

    return abs(node1->val - node2->val);
}

void get_min_dif(TreeNode* root, TreeNode* current, int& diff)
{
    if (root == nullptr)
        return;

    int current_diff = abs_diff(root, current);

    if (current_diff == 0)
        return;

    diff = current_diff < diff ? current_diff : diff;

    get_min_dif(root->left, current, diff);
    get_min_dif(root->right, current, diff);
}

int getMinimumDifference(TreeNode* root) {

    if (root == nullptr)
        return INT_MAX;

    queue<TreeNode*> nodes;

    nodes.push(root);

    int min_diff = INT_MAX;
    int diff = INT_MAX;

    while (!nodes.empty())
    {
        TreeNode* cur = nodes.front();
        nodes.pop();

        if (cur == nullptr)
            continue;

        get_min_dif(root, cur, diff);

        min_diff = diff < min_diff ? diff : min_diff;

        nodes.push(cur->left);
        nodes.push(cur->right);
    }
    return min_diff;

}
};