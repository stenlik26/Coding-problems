#include<iostream>
#include <string>
#include<vector>

using namespace std;

int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    
    int total = 0;
    for (size_t i = 0; i < points.size() - 1; i++)
    {
        total += max(abs(points[i+1][1] - points[i][1]), abs(points[i+1][0] - points[i][0]));
    }
    return total;
}

int main()
{
    return 0; 
}