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

void bfs(TreeNode* p, vector<int*>& nodes)
{
    queue<TreeNode*> s;

    s.push(p);

    if (p == nullptr)
        return;

    while (!s.empty())
    {
        TreeNode* current = s.front();
        s.pop();

        if (current == nullptr)
        {
            nodes.push_back(nullptr);
            continue;
        }
        else
        {
            nodes.push_back(&current->val);
        }

        s.push(current->left);
        s.push(current->right);


    }
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    vector<int*> p_nodes;
    vector<int*> q_nodes;
    bfs(p, p_nodes);
    bfs(q, q_nodes);

    if (p_nodes.size() != q_nodes.size())
        return false;

    for (size_t i = 0; i < p_nodes.size(); i++)
    {        
        if ((p_nodes[i] == nullptr || q_nodes[i] == nullptr) && p_nodes[i] != q_nodes[i])
            return false;

        if (p_nodes[i] != nullptr && q_nodes[i] != nullptr &&
            *p_nodes[i] != *q_nodes[i])
            return false;
    }

    return true;
}

int main()
{
    struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);

    struct TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(2);


    std::cout << isSameTree(root, root2) << "\n";
}
