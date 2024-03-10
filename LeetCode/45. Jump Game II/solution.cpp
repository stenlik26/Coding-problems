#include <bits/stdc++.h>
using namespace std;

int rec (const vector<int>& nums, vector<int>& cache, int pos)
{
    if(pos >= nums.size() - 1)
        return 0;

    if(cache[pos] != -1)
        return cache[pos];
        
    int res = INT_MAX - 2;
    for (size_t i = 1; i <= nums[pos]; i++)
    {
        int new_res = rec(nums, cache, pos + i);

        if(new_res < res)
            res = new_res;
    }
    return cache[pos] = res + 1;
}

int jump(vector<int>& nums) {
    vector<int> cache(nums.size(), -1);
    return rec(nums,cache,0);
}

int main()
{

    cout << "Test" << endl; 
    return 0; 

}