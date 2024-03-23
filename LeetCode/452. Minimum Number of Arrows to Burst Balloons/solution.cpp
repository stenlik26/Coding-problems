#include <bits/stdc++.h>
using namespace std;

int findMinArrowShots(vector<vector<int>> &points)
{
    sort(points.begin(), points.end(), [](const vector<int> &x, const vector<int> &y)
         { return x[1] < y[1]; });

    int last_pos = INT_MIN;
    uint32_t count = 0;

    for (size_t i = 0; i < points.size(); i++)
    {
        if(last_pos < points[i][0])
        {
            count++;
            last_pos = points[i][1];
        }
    }

    return count;
}

int main()
{
    vector<vector<int>> test = {{10,16},{2,8},{1,6},{7,12}};
    cout << findMinArrowShots(test) << endl;
    return 0;
}