#include<iostream>
#include <string>
#include <fstream>
#include<vector>

using namespace std;

int get_beat(int time, int dist)
{
    int count = 0;
    for (size_t i = 1; i < time; i++)
    {
        int current = (time - i) * i;
        if(current > dist)
            count++;
    }
    return count;
}

int main()
{
    //vector<int> times = {7,15,30};
    //vector<int> dists = {9,40,200};

    vector<int> times = {48,93,84,66};
    vector<int> dists = {261,1192,1019,1063};

    uint32_t total = 1;
    for (size_t i = 0; i < times.size(); i++)
    {   
        total *= get_beat(times[i], dists[i]);
    }
    cout << total << endl;

    return 0; 
}