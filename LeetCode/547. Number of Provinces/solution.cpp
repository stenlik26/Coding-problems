#include <iostream>
#include <vector>
using namespace std;

void find_component(int current, vector<vector<int>>& isConnected, bool* visited)
{
	visited[current] = true;

	for (size_t i = 0; i < isConnected.size(); i++)
	{
		if (isConnected[current][i] && !visited[i])
			find_component(i, isConnected, visited);
	}
}

int findCircleNum(vector<vector<int>>& isConnected) {

	size_t s = isConnected.size();
	bool* visited = new bool[s] {0};
	int comp = 0;

	for (size_t i = 0; i < s; i++)
	{
		if (!visited[i])
		{
			find_component(i, isConnected, visited);
			comp++;
		}
	}
	delete[] visited;
	return comp;
}

int main()
{

	vector<vector<int>> vec = {		
		{1,0,0,1},
		{0,1,1,0},
		{0,1,1,1},
		{1,0,1,1}
	};

	cout << findCircleNum(vec) << endl; // Should be 1
}

    