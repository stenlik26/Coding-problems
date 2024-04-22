#include <bits/stdc++.h>
using namespace std;

bool exact_square(const float val)
{
    return val - floor(val) <= 0.001;
}

int longestSquareStreak(vector<int> &nums)
{
    unordered_map<int, int> m;

    sort(nums.begin(), nums.end());
    int maxed = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        float x = sqrt(nums[i]);

        if (!exact_square(x))
        {
            m[nums[i]] = 1;
            if (maxed < 1)
                maxed = 1;
        }
        else
        {
            m[nums[i]] = m[x] + 1;

            if (maxed < m[nums[i]])
                maxed = m[nums[i]];
        }
    }
    return maxed > 1 ? maxed : -1;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> test = {4, 3, 6, 16, 8, 2};
    vector<int> test2 = {2, 3, 5, 6, 7};

    cout << longestSquareStreak(test) << endl;
    cout << longestSquareStreak(test2) << endl;

    return 0;
}

