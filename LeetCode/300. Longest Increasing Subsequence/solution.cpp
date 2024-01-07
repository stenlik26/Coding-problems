#include<iostream>
#include <string>
#include<vector>

using namespace std;

int rec(vector<int>& dp, vector<int>& nums)
{
    int max_len = 1;
    for (size_t i = 1; i < nums.size(); i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if(nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        max_len = max(max_len, dp[i]);   
    }
    return max_len;
}

int lengthOfLIS(vector<int>& nums) {
    if(nums.size() == 0)
        return 0;
        
    vector<int> dp (nums.size(), 1);
    int res = rec(dp, nums);
    return res;
}

int main()
{
    vector<int> test = {10,9,2,5,3,7,101,18};
    //cout <<lengthOfLIS(test) << endl; 

    vector<int> test2 = {0,1,0,3,2,3};
    //cout <<lengthOfLIS(test2) << endl; 

    vector<int> test3 = {7,7,7,7,7,7,7};
    //cout <<lengthOfLIS(test3) << endl; 

    vector<int> test4 = {3,5,6,2,5,4,19,5,6,7,12};
    cout << lengthOfLIS(test4)<<endl;

    vector<int> test6 = {0};
    cout << lengthOfLIS(test6)<<endl;

    return 0; 

}