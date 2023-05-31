#include <iostream>
#include <vector>
using namespace std;


vector<int> findDisappearedNumbers(vector<int>& nums) {
	bool* c = new bool[nums.size() + 1]{false};

	vector<int> res;

	for (size_t i = 0; i < nums.size(); i++)
	{
		c[nums[i]] = true;
	}

	for (size_t i = 1; i <= nums.size(); i++)
	{
		if (!c[i])
			res.push_back(i);
	}
	delete[] c;
	return res;
}

int main()
{
	vector<int> input = { 1,1 };
	vector<int> res = findDisappearedNumbers(input);

	for (size_t i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
}
