#include <bits/stdc++.h>
using namespace std;

bool rec(const vector<int>& nums, vector<int>& cache, int pos)
{
    if(pos == nums.size() - 1)
        return true;
    
    if(pos >= nums.size())
        return false;

    if(cache[pos] != -1)
        return (bool)cache[pos];

    bool res = false;
    for (size_t i = 1; i <= nums[pos]; i++)
    {
        bool new_res = rec(nums,cache, pos + i);
        if(new_res)
        {
            res = true;
            break;
        }
    }
    return cache[pos] = res;
}

bool canJump(vector<int>& nums) {
    vector<int> cache(nums.size(), -1);
    return rec(nums, cache, 0);
}

int main()
{
    return 0; 
}