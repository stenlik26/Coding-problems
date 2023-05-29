#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

    unordered_map<int, int> nums1_map;
    unordered_map<int, int> nums2_map;
	vector<int> res;

	for (size_t i = 0; i < nums1.size(); i++)
	{
		nums1_map[nums1[i]]++;
	}

	for (size_t i = 0; i < nums2.size(); i++)
	{
		nums2_map[nums2[i]]++;
	}

	for (size_t i = 0; i < nums1.size(); i++)
	{
		if (nums2_map[nums1[i]] != 0 && nums1_map[nums1[i]] != 0)
		{
			res.push_back(nums1[i]);
			nums1_map[nums1[i]]--;
			nums2_map[nums1[i]]--;
		}
	}
	return res;
}

int main()
{
    std::cout << "Hello World!\n";
}
