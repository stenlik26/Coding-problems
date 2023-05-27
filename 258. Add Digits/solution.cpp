// No258.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int add_digits_util(int num, int res)
{
    if (num == 0)
        return res;

    return add_digits_util(num / 10, res + num % 10);
}

int addDigits(int num) {

    int x = add_digits_util(num, 0);
    if (x < 10)
        return x;
    else 
        return addDigits(x);
}

int main()
{
    cout << addDigits(32) << endl;
    cout << addDigits(38) << endl;
    cout << addDigits(1294) << endl;
}
