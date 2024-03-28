#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    const int n = nums.size();

    for (size_t i = 0; i < nums.size(); i++)
    {
        if(nums[i] < 0)
            nums[i] = n + 1;
    }

    for (size_t i = 0; i < nums.size(); i++)
    {
        if(nums[i] < n)
            nums[nums[i]] = -nums[nums[i]];
    }

    for (size_t i = 0; i < nums.size(); i++)
    {
        if(nums[i] > 0)
            return i + 1;
    }
}

int main()
{

    cout << "Test" << endl; 
    return 0; 

}