#include<iostream>
#include <string>
#include <unordered_map>
#include<vector>

using namespace std;

int minOperations(vector<int>& nums) {
    unordered_map<int,int> freq;

    for (size_t i = 0; i < nums.size(); i++)
    {
        freq[nums[i]]++;
    }

    int res = 0;

    for(unordered_map<int,int>::iterator kvp = freq.begin(); kvp != freq.end(); ++kvp)
    {
        if(kvp->second == 1)
            return -1;

        res += kvp->second / 3;

        if(kvp->second % 3 != 0)
            res++;
    }
    
    return res;
}

int main()
{

    cout << "Test" << endl; 
    return 0; 

}