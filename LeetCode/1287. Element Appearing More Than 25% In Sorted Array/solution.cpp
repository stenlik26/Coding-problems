#include<iostream>
#include <string>
#include<vector>

using namespace std;

int findSpecialInteger(vector<int>& arr) {

    int max_num = arr[0];
    int max_count = 1;

    int curr_num = arr[0];
    int curr_count = 1;

    for (size_t i = 1; i < arr.size(); i++)
    {
        if(arr[i] != curr_num)
        {
            if(max_count < curr_count)
            {
                max_count = curr_count;
                max_num = curr_num;
            }
            curr_num = arr[i];
            curr_count = 1;
        }
        curr_count++;
    }

    if(max_count < curr_count)
        {
            max_count = curr_count;
            max_num = curr_num;
        }

    return max_num;    
}

int main()
{

    vector<int> test = {1,1};
    cout << findSpecialInteger(test)<<endl;
    return 0; 

}