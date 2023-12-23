#include<iostream>
#include <string>
#include <unordered_set>
#include<vector>

using namespace std;

const int sum_to_n(unsigned int n)
{
    return (n * (n + 1)) / 2;
}

vector<int> findErrorNums(vector<int>& nums) {
    unordered_set<int> seen;
    int sum = 0;
    int duplicating = nums[0];

    for (size_t i = 0; i < nums.size(); i++)
    {
        if(seen.find(nums[i]) != seen.end())
            duplicating = nums[i];
        else
        {
            seen.insert(nums[i]);
            sum += nums[i];
        }
    }
    return {duplicating, sum_to_n(nums.size()) - sum};
}

int main()
{

    cout << "Test" << endl; 
    return 0; 

}