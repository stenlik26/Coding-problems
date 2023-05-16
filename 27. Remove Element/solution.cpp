
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void shift_elements(vector<int>& nums, int from)
{
	for (size_t i = from; i < nums.size() - 1; i++)
	{
		nums[i] = nums[i + 1];
	}
}

int removeElement(vector<int>& nums, int val) {

	int shifts = 0;
	for (size_t i = 0; i < nums.size() - shifts; i++)
	{
		if (nums[i] == val)
		{
			shift_elements(nums, i);

			shifts++;
			i--;
		}
	}
	return nums.size() - shifts;

}

void print_result(vector<int>& vec, int el)
{
	cout << removeElement(vec, el) << " -";

	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << " " << vec[i];
	}
	cout << endl;
}

int main()
{
	vector<int> test1{ 3,2,2,3 };
	print_result(test1, 3);

	vector<int> test2{ 0,1,2,2,3,0,4,2 };
	print_result(test2, 2);
}
