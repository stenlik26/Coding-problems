#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int* left_arr = new int[nums.size()] {1};
    int* right_arr = new int[nums.size()] {1};
    
    vector<int> res;

    int current = 1;
    for (size_t i = 0; i < nums.size(); i++)
    {
        left_arr[i] = current;
        current *= nums[i];
    }
    current = 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        right_arr[i] = current;
        current *= nums[i];
    }

    for (size_t i = 0; i < nums.size(); i++)
    {
        res.push_back(left_arr[i] * right_arr[i]);
    }
    delete[] left_arr;
    delete[] right_arr;
    return res;
}

int main()
{
    vector<int> t1 = { 1,2,3,4 };
    vector<int> t2 = { -1,1,0,-3,3 };

    vector<int> res = productExceptSelf(t2);

    for (size_t i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

