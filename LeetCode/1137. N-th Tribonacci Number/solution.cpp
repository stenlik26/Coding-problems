#include <bits/stdc++.h>
using namespace std;

uint32_t trib_help(uint32_t x, uint32_t y, uint32_t z, int n)
{
    if (n == 0)
        return x;

    return trib_help(y, z, x + y + z, n - 1);
}

uint32_t tribonacci(int n)
{
    return trib_help(0,1,1,n);
}

int main()
{

    cout << tribonacci(4) << endl;
    return 0;
}