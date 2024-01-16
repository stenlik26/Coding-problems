#include<iostream>
#include <string>
#include<vector>

using namespace std;

void sortColors(vector<int>& nums) {
    int r_c = 0, w_c = 0, b_c = 0;

    for (size_t i = 0; i < nums.size(); i++)
    {
        if(nums[i] == 0)
            r_c++;
        if(nums[i] == 1)
            w_c++;
        if(nums[i] == 2)
            b_c++;
    }

    int i = 0;

    while(r_c != 0)
    { nums[i++] = 0; r_c--;}

    while(w_c != 0)
    { nums[i++] = 1; w_c--;}

    while(b_c != 0)
    { nums[i++] = 2; b_c--;}
    
}

int main()
{

    cout << "Test" << endl; 
    return 0; 

}