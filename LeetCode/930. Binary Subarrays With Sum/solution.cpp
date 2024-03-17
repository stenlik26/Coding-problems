#include <bits/stdc++.h>
using namespace std;

int count_subs(const vector<int>& nums, int start, int end)
{
    if(end < start)
        return 0;

    int ones_before = 1;
    int ones_after = 1;

    for (int i = start; i <= end && nums[i] != 1; i++)
        ones_before++;

    for (int j = end; j >= start && nums[j] != 1; j--)
        ones_after++;

    if(ones_after == ones_before && ones_after == end - start + 2)
        return  ((ones_after - 1)*ones_after) / 2;

    return ones_after  * ones_before;
}

int numSubarraysWithSum(vector<int>& nums, int goal) {
   
    const uint32_t s_len = nums.size() - 1;

    uint32_t left = 0;
    uint32_t right = 0;

    uint32_t cnt0 = 0;
    uint32_t res = 0;

    while (left <= s_len && right <= s_len)
    {
        if (nums[right] == 0)
            right++;
        else if (nums[right] == 1 && cnt0 < goal)
        {
            right++;
            cnt0++;
        }
        else
        {
            res += count_subs(nums, left, right - 1);

            while (nums[left] == 0)
                left++;
            
            left++;
            right++;
        }
    }
    if(left < right && cnt0 == goal)
        res += count_subs(nums, left, right - 1); 
    
    return res;
}

int main()
{
    vector<int> t2 = {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,1,0};
    cout << numSubarraysWithSum(t2,0)<<endl;


    return 0;
}
