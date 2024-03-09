#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int maxFrequencyElements(vector<int>& nums) {

    unordered_map<int,int> map;
    int max = 0, c = 0;

    for (size_t i = 0; i < nums.size(); i++)
    {
        const int val = ++map[nums[i]];

        if(val > max)
        {
            max = val;
            c =0;
        }
        if(val == max)
            c++;
    }
    return max * c;
}

int main()
{
    vector<int> w = {1,2,2,3,1,4};

    cout <<maxFrequencyElements(w) << endl; 
    return 0; 

}