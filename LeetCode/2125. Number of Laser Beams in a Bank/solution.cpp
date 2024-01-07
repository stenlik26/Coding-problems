#include<iostream>
#include <string>
#include<vector>

using namespace std;

int numberOfBeams(vector<string>& bank) {
    
    vector<int> device_per_row;
    const int rows = bank.size();
    for (int i = 0; i < rows; i++)
    {
        int row = 0;
        const int cols = bank[i].size();
        for (int j = 0; j < cols; j++)
        {
            if(bank[i][j] == '1')
                row++;
        }
        if(row != 0)
            device_per_row.push_back(row);
    }

    int res = 0;
    const int active_rows = device_per_row.size();
    for (int i = 0; i < active_rows - 1; i++)
    {
        res += device_per_row[i] * device_per_row[i+1];
    }
    
    return res;
}

int main()
{

    cout << "Test" << endl; 
    return 0; 

}