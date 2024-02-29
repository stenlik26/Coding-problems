#include<iostream>
#include <string>
#include<vector>
#include<queue>

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

bool even_lvl(const vector<TreeNode*> lvl)
{
    if(lvl.size() == 1)
        return lvl.front()->val % 2 != 0;

    for (size_t i = 0; i < lvl.size() - 1; i++)
    {
        if(lvl[i]->val >= lvl[i+1]->val || lvl[i]->val % 2 == 0)
            return false;
    }
    return lvl[lvl.size() - 1]->val % 2 != 0;
}

bool odd_lvl(const vector<TreeNode*> lvl)
{
    if(lvl.size() == 1)
        return lvl.front()->val % 2 == 0;

    for (size_t i = 0; i < lvl.size() - 1; i++)
    {
        if(lvl[i]->val <= lvl[i+1]->val || lvl[i]->val % 2 != 0)
            return false;
    }
    return lvl[lvl.size() - 1]->val % 2 == 0;
}


bool isEvenOddTree(TreeNode* root) {

    vector<TreeNode*> cur_lvl = {root};
    int level_num = 0;


    while(!cur_lvl.empty())
    {
        if((level_num % 2 == 0 && !even_lvl(cur_lvl)) || (level_num % 2 != 0 && !odd_lvl(cur_lvl)))
            return false;

        vector<TreeNode*> next;
        for (size_t i = 0; i < cur_lvl.size(); i++)
        {
            if(cur_lvl[i]->left != nullptr)
                next.push_back(cur_lvl[i]->left);

            if(cur_lvl[i]->right != nullptr)
                next.push_back(cur_lvl[i]->right);
        }
        cur_lvl = next;
        level_num++;
    }
    return true;
}

int main()
{
    TreeNode* test = new TreeNode(
        1,
        new TreeNode(10, new TreeNode(3, new TreeNode(12), new TreeNode(8)),nullptr), 
        new TreeNode(
            4, 
            new TreeNode(7, new TreeNode(6), nullptr), 
            new TreeNode(9, nullptr, new TreeNode(2)))
    );
    cout << isEvenOddTree(test) << endl; 
    return 0; 

}

//[1,10,4,3,null,7,9,12,8,6,null,null,2]