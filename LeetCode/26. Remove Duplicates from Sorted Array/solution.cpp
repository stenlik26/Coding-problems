#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int removeDuplicates(vector<int>& nums) {

	int unique = 1;
	int size = nums.size();
	for (int i = size - 1; i >= 1; i--)
	{
		if (nums[i] != nums[i - 1])
		{
			nums.push_back(nums[i]);
			unique++;
		}
	}
	nums.push_back(nums[0]);
	reverse(nums.begin(), nums.end());

	return unique;

}

void print_result(vector<int>& vec)
{
	cout << removeDuplicates(vec) << " -";

	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << " " << vec[i];
	}
	cout << endl;
}

int main()
{
	vector<int> test1{ 1,1,2 };
	print_result(test1);

	vector<int> test2{ 0,0,1,1,1,2,2,3,3,4 };
	print_result(test2);
}
