#include<iostream>
#include <string>
#include<vector>

using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    vector<vector<int>> transposed;
    
    for (size_t i = 0; i < matrix[0].size(); i++)
    {
        vector<int> row;
        for (size_t j = 0; j < matrix.size(); j++)
        {
            row.push_back(matrix[j][i]);
        }
        transposed.push_back(row);
    }

    return transposed;
}

int main()
{

    vector<vector<int>> t = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    vector<vector<int>> t2 = {
        {1,2,3},
        {4,5,6}
    };

    transpose(t);
    cout << endl;
    transpose(t2);
}