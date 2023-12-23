#include<iostream>
#include <string>

#include<unordered_set>

using namespace std;

struct hashFunction 
{ 
  size_t operator()(const pair<int ,  
                    int> &x) const
  { 
    return x.first ^ x.second; 
  } 
}; 

bool isPathCrossing(string path) {

    pair<int,int> current = {0,0};

    std::unordered_set<std::pair<int,int>, hashFunction> seen;

    seen.insert(current);

    for (size_t i = 0; i < path.size(); i++)
    {
        if(path[i] == 'N')
            current.first -= 1;
        else if(path[i] == 'S')
            current.first += 1;
        else if(path[i] == 'E')
            current.second += 1;
        else if(path[i] == 'W')
            current.second -= 1;

        if(seen.find(current) != seen.end())
            return true;

        seen.insert(current);
    }
    return false;
}

int main()
{

    cout << isPathCrossing("NES") << endl; 
    cout << isPathCrossing("NESWW") << endl; 
    cout << isPathCrossing("NES") << endl; 
    return 0; 

}