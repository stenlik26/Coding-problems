// No347.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

static bool cmp(pair<int, int>& vec1, pair<int, int>& vec2)
{
	return vec1.second > vec2.second;
}

vector<int> topKFrequent(vector<int>& nums, int k) {

	unordered_map<int, int> kvp;

	for (auto iter = nums.begin(); iter < nums.end(); iter++)
	{
		kvp[*iter]++;
	}

	vector<pair<int, int>> values_and_count;

	for (auto iter = kvp.begin(); iter != kvp.end(); iter++)
	{
		values_and_count.push_back({ iter->first, iter->second });
	}

	sort(values_and_count.begin(), values_and_count.end(), cmp);

	vector<int> answer;

	for (size_t i = 0; i < k; i++)
	{
		answer.push_back(values_and_count[i].first);
	}

	return answer;
}

int main()
{
	vector<int> a = { 1, 1, 1, 2, 2, 3 };
	int k = 2;

	vector<int> ans = topKFrequent(a, k);

	for (auto i = ans.begin(); i < ans.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}
