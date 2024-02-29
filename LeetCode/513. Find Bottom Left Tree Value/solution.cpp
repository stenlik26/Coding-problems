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

int findBottomLeftValue(TreeNode* root) {

    queue<queue<TreeNode*>> levels;

    queue<TreeNode*> current_lvl;

    int left_val;

    current_lvl.push(root);

    while(!current_lvl.empty())
    {

        left_val = current_lvl.front()->val;

        queue<TreeNode*> next_lvl;

        while(!current_lvl.empty())
        {
            TreeNode* cur_node = current_lvl.front();
            current_lvl.pop();

            if(cur_node->left != nullptr)
                next_lvl.push(cur_node->left);
            if(cur_node->right != nullptr)
                next_lvl.push(cur_node->right);
        }
        current_lvl = next_lvl;
    }

    return left_val;
}

int main()
{

    TreeNode* root = new TreeNode(2, new TreeNode(1), new TreeNode(3));

    cout << findBottomLeftValue(root) << endl;
    return 0; 

}