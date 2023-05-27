#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> summaryRanges(vector<int>& nums) {

	vector<string> res;
	
	int i = 0;

	while (i < nums.size())
	{
		int start = i;
		int end = i;
		while (i + 1 < nums.size() && nums[i] + 1 == nums[i+1])
		{
			end = i + 1;
			i++;
		}

		if (start != end)
			res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
		else
			res.push_back(to_string(nums[i]));
		i++;
	}
	return res;
}

int main()
{
	vector<int> t2{ -2147483648,-2147483647,2147483647 };
	vector<string> res2 = summaryRanges(t2);

	for (size_t i = 0; i < res2.size(); i++)
	{
		cout << res2[i] << " ";
	}
	cout << endl;

}
