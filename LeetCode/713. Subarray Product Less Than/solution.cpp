#include <bits/stdc++.h>
using namespace std;
int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    if(k <= 1)
        return 0;

    uint32_t current = 1;
    int res = 0;

    int l = 0, r = 0;
    const int n = nums.size();

    while(r < n)
    {
        current *= nums[r];

        while(current >= k)
        {
            current /= nums[l++];
        }
        res += r - l + 1;
        r++;
    }
    return res;
}

int main()
{


    vector<int> tw = {10,5,2,6};
        cout << numSubarrayProductLessThanK(tw,100) << endl;

    vector<int> t = {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3};
    cout << numSubarrayProductLessThanK(t,1000) << endl;

    vector<int> w = {57,44,92,28,66,60,37,33,52,38,29,76,8,75,22};
    cout << numSubarrayProductLessThanK(w,18) << endl;
    return 0;
}