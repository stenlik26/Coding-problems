#include <iostream>
#include <vector>
using namespace std;

vector<int> getAverages(vector<int>& nums, int k) {

    vector<int> res(nums.size(), 0);

	uint64_t current_sum = 0;
	int first = -1;

	for (size_t i = 0; i < nums.size(); i++)
	{
		if (i + 1 <= k || i + k >= nums.size())
		{
			res[i] = -1;
			continue;
		}

		if(first == -1)
		{
			for (size_t j = i-k; j <= i+k ; j++)
			{
				current_sum += nums[j];
			}
			first = i - k;
		}
		else
		{
			current_sum -= nums[first];
			first++;
			current_sum += nums[i + k];
		}
		res[i] = current_sum / ((2 * k) + 1);
	}
	return res;
}

int main()
{
	vector<int> t1 = { 7,4,3,9,1,8,5,2,6 };
	int k = 3;


	vector<int> res = getAverages(t1, k);

	for (size_t i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
}
