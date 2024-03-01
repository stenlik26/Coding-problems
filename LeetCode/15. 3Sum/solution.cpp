#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    
    sort(nums.begin(), nums.end());

    vector<vector<int>> res;

    for (size_t i = 0; i < nums.size() - 2; i++)
    {
        int target = nums[i];
        int left = i+1;
        int right = nums.size() - 1;

        if(i >= 1 && nums[i] == nums[i - 1])
            continue;
        
        while(left < right)
        {
            if(target + nums[left] + nums[right] > 0)
                right--;
            else if(target + nums[left] + nums[right] < 0)
                left++;
            else if(left != i+1 && nums[left-1] == nums[left])
            {
                left++;
            }
            else
            {
                vector<int> t = {target, nums[left], nums[right]};
                res.push_back(t);
                left++;
                right--;
            }
        }
        
    }
    return res;

}
int main()
{
    vector<int> test = {-1,0,1,2,-1,-4};
  
    
    vector<vector<int>> res = threeSum(test); 



    return 0; 

}

/*
// Algorithm without sorting, containing duplicate sets
vector<vector<int>> threeSum(vector<int>& nums) {
    
    vector<vector<int>> res;
    for (size_t i = 0; i < nums.size() - 2; i++)
    {
        int target = nums[i], target_left;
        unordered_set<int> seen;
        for (size_t j = i+1; j < nums.size(); j++)
        {
            target_left = 0 - target - nums[j];

            if(seen.find(target_left) != seen.end())
            {
                vector<int> t = {target, nums[j], *seen.find(target_left)};
                res.push_back(t);
            }
            seen.insert(nums[j]);
        }
        
    }
    return res;

}
*/