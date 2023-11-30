#include <iostream>
#include <string>
#include <queue>
#include <vector>

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

vector<vector<int>> levelOrder(TreeNode* root) {

    vector<vector<int>> result;
    std::queue<std::pair<TreeNode*, int>> nodes;
    
    int lvl = 0;
    nodes.push({root, lvl});

    vector<int> current_lvl;
    
    while(!nodes.empty())
    {
        TreeNode* cur = nodes.front().first;
        int cur_lvl = nodes.front().second;

        nodes.pop();

        if(cur == nullptr)
        {
            continue;
        }

        nodes.push({cur->left, cur_lvl + 1});
        nodes.push({cur->right, cur_lvl + 1});

        if(cur_lvl != lvl)
        {
            lvl++;
            result.push_back(current_lvl);
            current_lvl.clear();
        }
        current_lvl.push_back(cur->val);
    }
    if(!current_lvl.empty())
        result.push_back(current_lvl);
    return result;
}

int main()
{
    TreeNode* root = 
        new TreeNode(3, 
            new TreeNode(9, 
                new TreeNode(999, nullptr, nullptr),
                 nullptr),
            new TreeNode(20, 
                new TreeNode(15, nullptr, nullptr),
                new TreeNode(7, nullptr, nullptr))
    );

    vector<vector<int>> x = levelOrder(root);

    for(vector<int> lvl : x)
    {
        for(int val : lvl)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}