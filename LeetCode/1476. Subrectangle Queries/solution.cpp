#include<iostream>
#include <string>
#include<vector>

using namespace std;

class SubrectangleQueries {
public:
    vector<vector<int>>* rect;
    SubrectangleQueries(vector<vector<int>>& rectangle) {

        rect = new vector<vector<int>>;

        for (size_t i = 0; i < rectangle.size(); i++)
        {
            rect->push_back(rectangle[i]);
        }
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (size_t i = row1; i <= row2; i++)
        {
            for (size_t j = col1; j <= col2; j++)
            {
                (*rect)[i][j] = newValue;
            }   
        }
        
    }
    
    int getValue(int row, int col) {
        return (*rect)[row][col];
    }
};

int main()
{


}