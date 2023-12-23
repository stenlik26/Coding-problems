#include<iostream>
#include <string>
#include<vector>
#include<math.h>

using namespace std;

const int calc_avg(const vector<vector<int>>& img, int r, int c)
{
    int sum_cells = 0;
    int cell_count = 0;
    for (int i = -1; i <= 1; i++)
    {
        if(r + i < 0 || r + i >= img.size())
            continue;

        for(int j = -1; j <= 1; j++)
        {
            if(c + j < 0 || c + j >= img[0].size())
                continue;
            
            sum_cells += img[r+i][c+j];
            cell_count++;
        }
    }
    return floor(sum_cells / cell_count);
}

vector<vector<int>> imageSmoother(vector<vector<int>>& img) 
{
    vector<vector<int>> res(img.size(), vector<int>(img[0]));
    for (size_t i = 0; i < img.size(); i++)
    {
        for (size_t j = 0; j < img[0].size(); j++)
        {
            res[i][j] = calc_avg(img, i, j);
        }
        
    }
    return res;
}

int main()
{
    vector<vector<int>> img = {{100,200,100},{200,50,200},{100,200,100}};
    
    vector<vector<int>> res = imageSmoother(img);

    for (size_t i = 0; i < res.size(); i++)
    {
        for (size_t j = 0; j < res[i].size(); j++)
        {
           cout << res[i][j] << " ";
        }
        cout << endl;
        
    }
    
    return 0; 

}