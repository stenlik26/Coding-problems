#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;

static bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	return a.first < b.first;
}

bool containsNearbyDuplicate(vector<int>& nums, int k) {

	vector<pair<int, int>> set;

	for (size_t i = 0; i < nums.size(); i++)
	{
		set.push_back({ nums[i], i });
	}

	sort(set.begin(), set.end(), cmp);

	for (size_t i = 0; i < set.size() - 1; i++)
	{
		if (set[i].first == set[i + 1].first && abs(set[i].second - set[i + 1].second) <= k)
			return true;
	}

	return false;
}


int main()
{
	vector<int> n = { 1,0,1,1 };
	std::cout << containsNearbyDuplicate(n, 1) << endl;
}
