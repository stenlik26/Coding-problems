#include <iostream>
#include <vector>
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

bool is_symetric_level(vector<int*>& nodes)
{
    for (size_t i = 0; i < nodes.size() / 2; i++)
    {
        if (nodes[i] != nullptr && nodes[nodes.size() - 1 - i] != nullptr)
        {
            if ((*nodes[i] != *nodes[nodes.size() - 1 - i]))
                return false;
            else
                continue;
        }
        else if (nodes[i] == nullptr && nodes[nodes.size() - 1 - i] == nullptr)
            continue;
        else
            return false;
    }
    return true;
}

bool isSymmetric(TreeNode* p) {

    queue<pair<TreeNode*, int>> s;
    vector<int*> nodes;

    s.push({ p, 1 });

    if (p == nullptr)
        return true;

    int current_level = 1;

    while (!s.empty())
    {
        TreeNode* current = s.front().first;
        int level = s.front().second;
        s.pop();

        if (current_level != level)
        {
            if (!is_symetric_level(nodes))
                return false;
            nodes.clear();
            current_level = level;
        }

        if (current == nullptr)
        {
            nodes.push_back(nullptr);
            continue;
        }
        else
        {
            nodes.push_back(&current->val);
        }

        s.push({ current->left, current_level + 1 });
        s.push({ current->right, current_level + 1 });


    }
    return true;
}

int main()
{
    /*
    struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);*/
    
    
    struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->right = new TreeNode(3);

    root->right->right = new TreeNode(3);

    bool res = isSymmetric(root);

    std::cout << res << std::endl;
}
