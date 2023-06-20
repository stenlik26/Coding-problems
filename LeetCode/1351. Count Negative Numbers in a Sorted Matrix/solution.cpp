#include <iostream>
#include <vector>
using namespace std;

int countNegatives(vector<vector<int>>& grid) {

	uint16_t count = 0;
	for (size_t row = 0; row < grid.size(); row++)
	{
		int col = 0;
		for (col = 0; (col < grid[row].size() && grid[row][col] >= 0); col++);
			
		count += grid[row].size() - col;
	}
	return count;
}

int main()
{
	vector<vector<int>> grid = {
		{4,3,2,-1},
		{3,2,1,-1},
		{1,1,-1,-2},
		{ -1,-1,-2,-3}
	};

	cout << countNegatives(grid) << endl;
}
