#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {

    unordered_set<int> seen;
    vector<int> res;

    for(const int& x : nums)
    {
        if(seen.find(x) != seen.end())
        {
            res.push_back(x);
            continue;
        }
        
        res.push_back(x);
    }
    
    return res;
}

int main()
{
    vector<int> t1 = {4,3,2,7,8,2,3,1};

    vector<int> res = findDuplicates(t1);

    for(const int& x : res)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0; 

}