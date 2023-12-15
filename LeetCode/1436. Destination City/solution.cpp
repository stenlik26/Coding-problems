#include<iostream>
#include <string>
#include <unordered_map>
#include<vector>

using namespace std;

string destCity(vector<vector<string>>& paths) {
    unordered_map<string, string> graph;

    for (size_t i = 0; i < paths.size(); i++)
    {
        graph.insert({paths[i][0], paths[i][1]});
    }
    

    for (auto itr = graph.begin(); itr != graph.end(); itr++)
    {
        if(graph.find(itr->second) == graph.end())
            return itr->second;
    }
    
}

int main()
{

    vector<vector<string>> test = {
      {"B","C"},
      {"D","B"},
      {"C","A"}  
    };

    cout << destCity(test)<<endl;
    return 0; 

}