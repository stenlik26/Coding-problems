// No190.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;

uint32_t two_to(int x)
{
    return (1 << x);
}

uint32_t reverseBits(uint32_t n) {
    uint32_t n_new = 0;

    for (size_t i = 0; i < 32; i++)
    {
        if(2*i <= 31)
            n_new += ((n & two_to(i)) << 31 - 2 * i);
        else
            n_new += ((n & two_to(i)) >> 2 * i - 31);

    }
    return n_new;
}

int main()
{
    cout << reverseBits(43261596) << " ~ " << "964176192" << endl;
    cout << reverseBits(4294967293) << " ~ " << "3221225471 " << endl;
}

