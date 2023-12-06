#include<iostream>
#include <string>
#include <fstream>
#include<vector>

using namespace std;

int get_beat(uint64_t time, uint64_t dist)
{
    int count = 0;
    for (size_t i = 1; i < time; i++)
    {
        uint64_t current = (time - i) * i;
        if(current > dist)
            count++;
    }
    return count;
}

int main()
{
    //uint64_t time = 71530;
    //uint64_t dist = 940200;

    uint64_t time = 48938466;
    uint64_t dist = 261119210191063;

    cout << get_beat(time, dist) << endl;

    return 0; 
}