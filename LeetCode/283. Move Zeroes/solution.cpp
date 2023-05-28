#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {

	int moved = 0;

	for (size_t i = 0; i < nums.size() - moved; i++)
	{
		if (nums[i] == 0)
		{
			for (size_t j = i; j < nums.size() - moved - 1; j++)
			{
				swap(nums[j], nums[j + 1]);
			}
			moved++;
			i--;
		}
	}
}

int main()
{
	vector<int> test = { 0,1,0,3,12 };

	moveZeroes(test);

	for (size_t i = 0; i < test.size(); i++)
	{
		cout << test[i] << " ";
	}
	cout << endl;
}
