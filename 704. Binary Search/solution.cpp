#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
            return mid;

        if (nums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main()
{
    vector<int> test = { -1,0,3,5,9,12 };
    cout << search(test, 9) << endl;
}
