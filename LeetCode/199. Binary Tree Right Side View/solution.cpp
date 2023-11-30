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

vector<int> rightSideView(TreeNode* root)  {

    vector<int> result;
    std::queue<std::pair<TreeNode*, int>> nodes;
    
    int lvl = 0;
    nodes.push({root, lvl});

    int current_lvl_last = 101;
    
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
            result.push_back(current_lvl_last);
        
        }
        current_lvl_last = cur->val;
    }

    if(result.empty() && current_lvl_last != 101)
        result.push_back(current_lvl_last);
    else if(!result.empty() && result.back() != current_lvl_last)
        result.push_back(current_lvl_last);

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
               nullptr,
                nullptr)
    );

    vector<int> x = rightSideView(nullptr);


    for(int val : x)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}