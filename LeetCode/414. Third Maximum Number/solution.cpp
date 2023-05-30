#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static bool cmp(int& x, int& y)
{
    return x > y;
}

int thirdMax(vector<int>& nums) {

    sort(nums.begin(), nums.end(), cmp);

    int skiped = 0;
    for (size_t i = 0; i < nums.size() - 1; i++)
    {
        if (skiped == 2)
            return nums[i];

        if (nums[i] == nums[i + 1])
            continue;
        skiped++;
    }
    return (skiped==2) ? nums[nums.size() - 1] : nums[0];
}

int main()
{
    vector<int> t1 = { 1,2,3 };
    vector<int> t2 = { 1,2};
    vector<int> t3 = { 2,2,3,1 };

    cout << thirdMax(t1) << endl;
    cout << thirdMax(t2) << endl;
    cout << thirdMax(t3) << endl;
}

