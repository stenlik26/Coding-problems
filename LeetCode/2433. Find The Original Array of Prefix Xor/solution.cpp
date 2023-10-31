#include<iostream>
#include <string>
#include<vector>

using namespace std;

vector<int> findArray(vector<int>& pref) {
    vector<int> res(pref.size());
    res[0] = pref[0];

    for (size_t i = 1; i < pref.size(); i++)
    {
        res[i] = pref[i] ^ pref[i - 1];
    }
    return res;
}

int main()
{
    vector<int> input = {5,2,0,3,1};
    vector<int> res = findArray(input);

    for (auto x : res)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";
    
}