#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int>& nums){
    int first_non_zero =0;

    while(first_non_zero < nums.size() && nums[first_non_zero] < 0)
        first_non_zero++;

    
    vector<int> res;

    int left = first_non_zero - 1, right = first_non_zero;

    while(right < nums.size() && left >= 0)
    {
        if(nums[right] > abs(nums[left]))
        {
            res.push_back(nums[left] * nums[left]);
            left --;
        }
        else
        {
            res.push_back(nums[right] * nums[right]);
            right++;
        }
    }

    while(left >= 0)
    {
        res.push_back(nums[left] * nums[left]);
        left --;
    }

    while(right < nums.size())
    {
        res.push_back(nums[right] * nums[right]);
        right++;
    }

    return res;
}

int main()
{

    vector<int> test = {-4,-1,0,3,10};
    vector<int> res2 = sortedSquares(test);

    return 0; 

}