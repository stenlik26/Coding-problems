#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

	unordered_map<int, int> map;
	vector<int> result;

	for (size_t i = 0; i < nums1.size(); i++)
	{
		map[nums1[i]]++;
	}

	for (size_t i = 0; i < nums2.size(); i++)
	{
		if (map[nums2[i]])
		{
			result.push_back(nums2[i]);
			map[nums2[i]] = 0;
		}
	}
	return result;
}

int main()
{
    std::cout << "Hello World!\n";
}
