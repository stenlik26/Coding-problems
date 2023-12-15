#include<iostream>
#include <string>
#include<vector>

using namespace std;

vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
    vector<int> zerosOnRow(grid.size()), onesOnRow(grid.size()), zerosOnCol(grid[0].size()), onesOnCol(grid[0].size());
    vector<vector<int>> res(grid.size(), vector<int>(grid[0].size()));

    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[0].size(); j++)
        {
            if(grid[i][j] == 0)
            {
                zerosOnRow[i]++;
                zerosOnCol[j]++;
            }
            else
            {
                onesOnRow[i]++;
                onesOnCol[j]++;
            }
        }
        
    }

    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[0].size(); j++)
        {
            res[i][j] = onesOnRow[i] + onesOnCol[j] - zerosOnRow[i] - zerosOnCol[j];
        }
        
    }
    return res;
}

int main()
{

    vector<vector<int>> test = {
    {0,1,1},
    {1,0,1},
    {0,0,1}
    };

    vector<vector<int>> res = onesMinusZeros(test);


    for(const vector<int>& row : res)
    {
        for(const int& x : row)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0; 

}