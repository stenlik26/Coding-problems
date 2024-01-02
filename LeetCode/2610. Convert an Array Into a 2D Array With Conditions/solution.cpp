#include<iostream>
#include <string>
#include<vector>
#include<unordered_map>

using namespace std;
vector<vector<int>> findMatrix(vector<int>& nums) {
    
    unordered_map<int,int> freq_map;
    int max_freq = 0;

    for (size_t i = 0; i < nums.size(); i++)
    {
        freq_map[nums[i]]++;

        max_freq = max(freq_map[nums[i]], max_freq);
    }

    vector<vector<int>> res (max_freq, vector<int>());

    for(unordered_map<int,int>::iterator kvp = freq_map.begin(); kvp != freq_map.end(); ++kvp)
    {
        const int rows = kvp->second;
        const int val = kvp->second;
        
        for (size_t i = 0; i < rows; i++)
        {
            res[i].push_back(val);
        }        
    }
    
    return res;
}

int main()
{
    vector<int> test = {1,3,4,1,2,3,1};

    vector<vector<int>> res = findMatrix(test);
    cout << "Test" << endl; 
    return 0; 

}