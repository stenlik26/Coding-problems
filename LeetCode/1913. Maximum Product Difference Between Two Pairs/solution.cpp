#include<iostream>
#include <string>
#include<vector>
#include <limits.h>

using namespace std;

int maxProductDifference(vector<int>& nums) {
 int max_a = INT_MIN;
 int max_b = INT_MIN;

 int min_a = INT_MAX;
 int min_b = INT_MAX;

 for (size_t i = 0; i < nums.size(); i++)
 {
    int& current = nums[i];
    if(current > max_a)
    {
        max_b = max_a;
        max_a = current;
    }
    else if(current > max_b)
    {
        max_b = current;
    }
    
    if(current < min_a)
    {
        min_b = min_a;
        min_a = current;
    }
    else if(current < min_b)
    {
        min_b = current;
    }
 }
    return (max_a*max_b) - (min_a*min_b);    
}

int main()
{

    vector<int> t = {4,2,5,9,7,4,8};
    cout << maxProductDifference(t)<<endl;
    return 0; 

}
