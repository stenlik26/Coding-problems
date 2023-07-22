#include <iostream>

int findComplement(int num) {

	int i = 31;
	for (; i >= 0; i--)
	{
		if ((1 << i) & num)
			break;
	}
	
	int new_num = 0;
	for (size_t j = 0; j <= i; j++)
	{
		new_num += (num & (1 << j)) ^ (1 << j);
	}
	return new_num;
}

int main()
{
    std::cout << findComplement(5) ;
}
