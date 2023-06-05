#include <iostream>
#include <vector>
using namespace std;

bool compare_d(double& a, double& b)
{
    return abs(a - b) < 0.001;
}

bool checkStraightLine(vector<vector<int>>& coordinates) {

    int a_x = coordinates[0][0];
    int a_y = coordinates[0][1];

    int p_x = coordinates[1][0] - a_x;
    int p_y = coordinates[1][1] - a_y;

    for (size_t i = 2; i < coordinates.size(); i++)
    {
        double scalar = 0;
        if (p_x != 0)
        {
            scalar = (coordinates[i][0] - a_x) / (double)p_x;

            double r1 = scalar * p_y + a_y;
            double r2 = coordinates[i][1];

            if (!compare_d(r1,r2))
                return false;
        }
        else if (p_y != 0)
        {
            scalar = (coordinates[i][1] - a_y) / (double)p_y;

            double r1 = scalar * p_x + a_x;
            double r2 = coordinates[i][0];

            if (!compare_d(r1, r2))
                return false;
        }
        else if (a_x != coordinates[i][0] || a_y != coordinates[i][1])
            return false;
    }
    return true;
}

int main()
{
    vector<vector<int>> t1 = { {1,2},{2,3},{3,4},{4,5},{5,6},{6,7} };
    vector<vector<int>> t2 = { {1,1},{2,2},{3,4},{4,5},{5,6},{7,7} };
    vector<vector<int>> t4 = { {8,78} ,{2,18},{-1,-12},{-5,-52},{-4,-42},{-8,-82},{3,28},{9,88} };
    vector<vector<int>> t3 = { {0,0},{0,1},{0,-1} };
    vector<vector<int>> t5 = {{9, 77}, {14, 127}, {5, 37}, {-4, -53}, {0, -13}, {-1, -23}, {-10, -113}, {-14, -153}, {11, 97}, {12, 107}, {10, 87}, {1, -3}, {3, 17}, {-12, -133}};
    cout << checkStraightLine(t5) << endl;
};

