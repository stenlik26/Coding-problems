#include<iostream>
#include <string>
#include<vector>

using namespace std;


int minCost(string colors, vector<int>& neededTime) {

    uint32_t min_time = 0;

    char last_col = colors[0];
    int max_time_idx = 0;
    uint32_t current_seq_sum = neededTime[0];

    for (size_t i = 1; i < colors.size(); i++)
    {
        if(last_col != colors[i])
        {
            min_time += current_seq_sum - neededTime[max_time_idx];
            current_seq_sum = 0;
            last_col = colors[i];
            max_time_idx = i;
        }

        if(neededTime[i] > neededTime[max_time_idx])
            max_time_idx = i;
        
        current_seq_sum += neededTime[i];
    }

    if(current_seq_sum != 0)
        min_time += current_seq_sum - neededTime[max_time_idx];
    
    return min_time;
}

int main()
{
    vector<int> test1 = {1,2,3,4,5};
    cout << minCost("abaac", test1) << endl; 

    vector<int> test2 = {1,2,3};
    cout << minCost("abc", test2) << endl; 

    vector<int> test3 = {1,2,3,4,1};
    cout << minCost("aabaa", test3) << endl; 
    return 0; 

}