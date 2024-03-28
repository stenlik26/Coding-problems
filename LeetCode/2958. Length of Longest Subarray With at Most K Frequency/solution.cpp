#include <bits/stdc++.h>
using namespace std;

int maxSubarrayLength(vector<int>& nums, int k) {

    int max_len = 0;
    unordered_map<int,int> cnt;
    const int n = nums.size();
    int l = 0, r = 0;

    while(r < n)
    {
        cnt[nums[r]]++;

        while(cnt[nums[r]] > k && l <= r)
        {
            cnt[nums[l]]--;
            l++;
        }

        if(r - l + 1 > max_len)
            max_len = r - l + 1;

        r++;
    }
    return max_len;
}

int main()
{

    cout << "Test" << endl; 
    return 0; 

}