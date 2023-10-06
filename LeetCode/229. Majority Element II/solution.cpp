#include<iostream>
#include <string>
#include<vector>
#include <unordered_map>

using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    
    vector<int> res;

    unordered_map<int, int> num_count;

    uint32_t treshold = nums.size() / 3;

    for(auto i = nums.begin(); i != nums.end(); ++i)
    {
        num_count[*i]++;
    }

    for(auto kvp = num_count.begin(); kvp != num_count.end(); ++kvp)
    {
        if(kvp->second > treshold)
            res.push_back(kvp->first);
    }

    return res;
}

int main()
{

    vector<int> test_case = {3,2,3};

    vector<int> res = majorityElement(test_case);

    return 0; 

}