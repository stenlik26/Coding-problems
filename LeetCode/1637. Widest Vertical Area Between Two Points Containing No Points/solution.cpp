#include<iostream>
#include <string>
#include<vector>
#include<algorithm>

using namespace std;

int maxWidthOfVerticalArea(vector<vector<int>>& points) {
    vector<int> xs;

    int max_diff = 0;

    for (size_t i = 0; i < points.size(); i++)
    {
        xs.push_back(points[i][0]);
    }

    sort(xs.begin(), xs.end());
    
    for (size_t i = 0; i < xs.size() - 1; i++)
    {
        int diff = xs[i+1] - xs[i];

        if(max_diff < diff)
            max_diff = diff;
    }
    return max_diff;
}

int main()
{
    vector<vector<int>> test = {{3,1},{9,0},{1,0},{1,4},{5,3},{8,8}};

    cout << maxWidthOfVerticalArea(test)<<endl;
    cout << "Test" << endl; 
    return 0; 

}