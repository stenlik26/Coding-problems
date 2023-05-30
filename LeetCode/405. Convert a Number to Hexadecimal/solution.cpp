#include <iostream>
#include <string>
using namespace std;

char int_to_hex(int x)
{
	if (x <= 9)
		return '0' + x;
	else
		return ('a' + (x - 10));
}

string toHex(int num) {
	
	if (num == 0)
		return "0";

	string temp = "";
	string res = "";
	for (size_t i = 0; i < 8; i++)
	{
		int x = (num & 15);
		temp += int_to_hex((num & 15));
		num = num >> 4;
	}
	int j = temp.size() - 1;
	while (temp[j] == '0')
		j--;

	for (int i = j; i >= 0; i--)
	{
		res += temp[i];
	}

	return res;
}

int main()
{
	cout << toHex(5564) << endl;
}
