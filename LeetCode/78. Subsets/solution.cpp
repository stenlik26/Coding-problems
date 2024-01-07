#include<iostream>
#include <string>
#include<vector>

using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {

    const int arr_size = nums.size();
    int sets_count = 2 << arr_size - 1;

    vector<vector<int>> res;

    for (int i = 0; i < sets_count; i++)
    {
        vector<int> current_set;
        for (int bit = 0; bit < arr_size; bit++)
        {
            if((i & (1 << bit)) != 0)
            {
                current_set.push_back(nums[bit]);
            }
        }
        res.push_back(current_set);
    }
    return res;
}

int main()
{
    vector<int> test = vector<int> {1,2,3};
    vector<vector<int>> out = subsets(test);
    return 0; 

}