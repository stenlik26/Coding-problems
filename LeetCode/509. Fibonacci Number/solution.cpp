#include <iostream>
using namespace std;
int fib_mem(int n, uint32_t* mem)
{
    if (mem[n] != 0)
        return mem[n];

    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    mem[n] = fib_mem(n - 1, mem) + fib_mem(n - 2, mem);
    return mem[n];
}

int fib(int n) {

    uint32_t* mem = new uint32_t[31]{0};

    uint32_t res = fib_mem(n, mem);

    delete[] mem;

    return res;
}



int main()
{
    cout << fib(2) << endl;
    cout << fib(3) << endl;
    cout << fib(4) << endl;

}
