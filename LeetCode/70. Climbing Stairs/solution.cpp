
#include <iostream>

int climbStairs_mem(int n, unsigned int* mem)
{
    if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else if (mem[n] != 0)
        return mem[n];
    else {
        mem[n] = climbStairs_mem(n - 1, mem) + climbStairs_mem(n - 2, mem);
        return mem[n];
    }
}

int climbStairs(int n) {
    unsigned int* mem = new unsigned int[n + 1]{0};
    long result = climbStairs_mem(n, mem);
    delete[] mem;
    return result;
}

int main()
{
    std::cout << climbStairs(26) << std::endl;
}
