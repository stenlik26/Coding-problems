#include<iostream>
#include <string>
#include<vector>

using namespace std;

int maxProduct(vector<int>& nums) {
    int max_i = 0;
    int max_j = 1;

    for (size_t i = 2; i < nums.size(); i++)
    {
        if(nums[i] > nums[max_i] && i != max_j)
        {
            if(nums[max_i] > nums[max_j])
                max_j = max_i;
            max_i = i;
            
        }
        
        if(nums[i] > nums[max_j] && i != max_i)
            max_j = i;
    }
    
    return (nums[max_i] - 1) * (nums[max_j] - 1);
}

int main()
{

    vector<int> t1 = {2,2,1,8,1,5,4,5,2,10,3,6,5,2,3};
    cout << maxProduct(t1)<<endl;
    return 0; 

}