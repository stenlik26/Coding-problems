#include<iostream>
#include <string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;
int findJudge(int n, vector<vector<int>>& trust) {

    if(n == 1)
        return 1;

    unordered_map<int, vector<int>> like_relation;
    unordered_set<int> candidates;

    for (size_t i = 1; i <= n; i++)
        candidates.insert(i);
    

    for (size_t i = 0; i < trust.size(); i++)
    {
        //(x,y) ---> Y is liked by X
        like_relation[trust[i][1]].push_back(trust[i][0]);
        candidates.erase(trust[i][0]);
    }
    
    for (auto kvp = like_relation.begin(); kvp != like_relation.end(); ++kvp)
    {
        if(candidates.find(kvp->first) == candidates.end())
            continue;

        if(kvp->second.size() == n-1)
            return kvp->first;
    }
    return -1;

}

int main()
{

    vector<int> t1 = {1,2};
    vector<int> t2 = {2,3};
    //vector<int> t3 = {3,1};
    vector<vector<int>> test = {t1,t2};
    
    cout << findJudge(3, test) << endl;
    return 0; 

}