#include<iostream>
#include <string>
#include<vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> groupThePeople(vector<int>& groupSizes) {

    vector<vector<int>> result;

    unordered_map<int, vector<int>> people_by_group_size;

    for (int i = 0; i < groupSizes.size(); i++)
    {
        people_by_group_size[groupSizes[i]].push_back(i);
    }
    
    for (auto i = people_by_group_size.begin(); i != people_by_group_size.end(); ++i)
    {
        vector<int> current_group;
        
        for (size_t j = 0; j <= i->second.size(); j++)
        {
            if(current_group.size() == i->first)
            {
                result.push_back(current_group);
                current_group.clear();

                if(j == i->second.size())
                    break;  
            }

            current_group.push_back(i->second[j]);
        }
    }
    return result;
}

int main()
{

    vector<int> input = {3,3,3,3,3,1,3};
    vector<vector<int>> res = groupThePeople(input);

    for (auto i = res.begin(); i != res.end(); ++i)
    {
        for (auto j = i->begin(); j != i->end(); ++j)
        {
            cout << *j << " ";
        }
        cout << endl;
        
    }


}