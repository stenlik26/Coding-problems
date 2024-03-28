#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {
    
    unordered_set<int> seen;

    for (size_t i = 1; i < nums.size(); i++)
    {
        if(seen.find(nums[i]) != seen.end())
            return nums[i];

        seen.insert(nums[i]);
    }
    return -1;
}

int main()
{

    cout << "Test" << endl; 
    return 0; 

}