
// No504.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

std::string convertToBase7(int num) {
	std::string base7_num = "";
	std::string base7_reversed = "";
	bool negative = false;
	if (num == 0)
		return "0";
	if (num < 0)
	{
		negative = true;
		num *= -1;
	}
	while (num != 0)
	{
		base7_num += to_string(num % 7);
		num /= 7;
	}

	if (negative)
	{
		base7_num += '-';
	}
	for (int i = base7_num.size() - 1; i >= 0; i--) {
		base7_reversed += base7_num[i];
	}
	return base7_reversed;
}

int main()
{
    std::cout << convertToBase7(100);
}
