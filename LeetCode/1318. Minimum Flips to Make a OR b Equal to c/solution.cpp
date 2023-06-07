#include <iostream>
using namespace std;
int minFlips(int a, int b, int c) {

	int flips = 0;
	for (size_t i = 0; i <= 31; i++)
	{
		bool a_bit = a & (1 << i);
		bool b_bit = b & (1 << i);
		bool c_bit = c & (1 << i);

		if ((a_bit | b_bit) == c_bit)
			continue;

		if (a_bit == true && b_bit == true)
		{
			flips++;
		}

		flips++;
	}
	return flips;

}

int main()
{
	cout << minFlips(4, 2, 7) << endl;
}
