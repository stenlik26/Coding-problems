#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool containsDuplicate(vector<int>& nums) {

    unordered_set<int> set;

	for (size_t i = 0; i < nums.size(); i++)
	{
		if (set.find(nums[i]) != set.end())
			return true;

		set.insert(nums[i]);
	}
	return false;
}


int main()
{
    vector<int> n = { 1,2,3,4 };
	cout << containsDuplicate(n) << endl;
}
