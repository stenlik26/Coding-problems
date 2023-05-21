#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
	int n1iter = 0;
	int n2iter = 0;

	vector<int> new_nums;

	while (n1iter < m && n2iter < n)
	{
		if (nums1[n1iter] < nums2[n2iter])
		{
			new_nums.push_back(nums1[n1iter]);
			n1iter++;
		}
		else
		{
			new_nums.push_back(nums2[n2iter]);
			n2iter++;
		}
	}

	while (n1iter < m)
	{
		new_nums.push_back(nums1[n1iter]);
		n1iter++;
	}

	while (n2iter < n)
	{
		new_nums.push_back(nums2[n2iter]);
		n2iter++;
	}

	nums1 = new_nums;
}

int main()
{
	vector<int> m = { 1,2,3,0,0,0 };
	vector<int> n = { 2,5,6 };

	merge(m, 3, n, 3);

	for (size_t i = 0; i < m.size(); i++)
	{
		cout << m[i] << " ";
	}cout << endl;
}
