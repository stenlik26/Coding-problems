#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int cur_sum = 0, max_sum = INT_MAX;

    for (size_t i = 0; i < nums.size(); i++)
    {
        cur_sum += nums[i];

        if (cur_sum > max_sum)
            max_sum = cur_sum;

        if(cur_sum < 0)
            cur_sum = 0;
    }
    return max_sum;
}

int main()
{
    vector<int> t = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(t) << endl;
    return 0;
}