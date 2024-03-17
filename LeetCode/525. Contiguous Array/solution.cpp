#include <bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int> &nums)
{
    unordered_map<int, int> sum_to_pos;
    int cur_sum = 0;
    int best_len = 0;

    for (size_t i = 0; i < nums.size(); i++)
    {
        cur_sum += (nums[i] == 1) ? 1 : -1;

        if ((sum_to_pos.find(cur_sum) != sum_to_pos.end())) 
        {
            const int comp = i - sum_to_pos[cur_sum];

            if (comp > best_len)
                best_len = comp;
        }

        if(cur_sum == 0 && i + 1 > best_len)
            best_len = i;

        else
            sum_to_pos[cur_sum] = i + 1;
    }
    if (cur_sum == 0)
        return nums.size();
    return best_len;
}

int main()
{
    vector<int> t = {0, 0, 0, 1, 1, 0, 1, 1, 1, 1};
    cout << findMaxLength(t) << endl;
    return 0;
}