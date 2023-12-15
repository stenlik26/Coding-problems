#include<iostream>
#include <string>
#include<vector>

using namespace std;

int numSpecial(vector<vector<int>>& mat) {
    int res = 0;
    vector<int> ones_per_row(mat.size());
    vector<int> ones_per_col(mat[0].size());

    for (size_t row = 0; row < mat.size(); row++)
    {
        for (size_t col = 0; col < mat[0].size(); col++)
        {
            if(mat[row][col] == 1)
                ones_per_row[row]++;
        }
    }

    for (size_t col = 0; col < mat[0].size(); col++)
    {
        for (size_t row = 0; row < mat.size(); row++)
        {
            if(mat[row][col] == 1)
                ones_per_col[col]++;
        }
    }

    for (size_t row = 0; row < mat.size(); row++)
    {
        for (size_t col = 0; col < mat[0].size(); col++)
        {
            if(mat[row][col] == 1  && ones_per_col[col] == 1 && ones_per_row[row] == 1)
                res++;
        }
    }
    return res;
}

int main()
{

    vector<vector<int>> mat = {
        {1,0,0},
        {0,0,1},
        {1,0,0}
    };

    cout << numSpecial(mat) << endl;
    return 0; 

}