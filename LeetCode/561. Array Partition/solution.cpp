#include<iostream>
#include <string>
#include<vector>
#include<algorithm>

using namespace std;

int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());
    
    int sum = 0;
    for (size_t i = 0; i < nums.size(); i+=2)
    {
        sum += min(nums[i], nums[i+1]);
    }
    return sum;
}

int main()
{

    cout << "Test" << endl; 
    return 0; 

}