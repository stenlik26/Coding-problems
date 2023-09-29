#include <iostream>
#include <vector>
using namespace std;

/*bool isMonotonic(const vector<int>& nums) 
{
    short diff;
    if (nums[0] == nums[nums.size() - 1])
        diff = 0;
    else
        diff = (nums[0] - nums[nums.size() - 1]) > 0 ? -1 : 1;

    for (size_t i = 0; i < nums.size() - 1; i++)
    {
        if ((nums[i + 1] - nums[i] < 0 && diff != -1) ||
            (nums[i + 1] - nums[i] > 0 && diff != 1))
            return false;
    }
    return true;
}*/

bool isMonotonic(const vector<int>& nums)
{
    bool is_increasing = true;
    bool is_decreasing = true;

    for (size_t i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i + 1] > nums[i])
            is_decreasing = false;
        else if (nums[i + 1] < nums[i])
            is_increasing = false;
    }
    return is_decreasing || is_increasing;
}



int main()
{
    
    cout << isMonotonic({ 1,2,2,3 }) << endl;
    cout << isMonotonic({ 6,5,5,4 }) << endl;
    cout << isMonotonic({ 1,3,2 }) << endl;
}
