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

TreeNode* get_bst_help(const vector<int>& nums, int start, int end)
{
    if(start > end)
        return nullptr;

    if(start == end)
        return new TreeNode(nums[start]);

    if(abs(end - start) <= 1)
    {
        if(nums[start] > nums[end])
            return new TreeNode(nums[start], new TreeNode(nums[end]), nullptr);
        else
             return new TreeNode(nums[start], nullptr, new TreeNode(nums[end]));
    }

    int mid = (end + start) / 2;

    return new TreeNode(nums[mid], get_bst_help(nums, start, mid - 1), get_bst_help(nums, mid + 1, end));
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return get_bst_help(nums, 0, nums.size() - 1);
}

int main()
{
    //vector<int> test = {-10, -3, 0, 5, 9};
    //vector<int> test = {1,3};
    vector<int> test = {0,1,2,3,4,5,6};
    TreeNode* root = sortedArrayToBST(test);


    return 0; 

}