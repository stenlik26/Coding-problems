#include <iostream>
#include <vector>
using namespace std;

int count_bits(int x)
{
	uint16_t count = 0;
	for (size_t i = 0; i <= 31; i++)
	{
		if (x & (1 << i))
			count++;
	}
	return count;
}

vector<int> countBits(int n) {

	vector<int> res;
	for (size_t i = 0; i <= n; i++)
	{
		res.push_back(count_bits(i));
	}
	return res;
}

int main()
{
	vector<int> res = countBits(5);

	for (size_t i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
}
