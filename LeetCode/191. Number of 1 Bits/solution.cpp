#include <iostream>
using namespace std;

int hammingWeight(uint32_t n) {
    int total = 0;

	for (size_t i = 0; i <= 31; i++)
	{
		total += (n & (1 << i)) ? 1 : 0;
	}
	return total;
}


int main()
{
	cout << "Num: 101 (5) " << hammingWeight(5) << endl;
}
