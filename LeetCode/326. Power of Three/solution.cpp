#include <iostream>
bool isPowerOfThree(int n) {
    if (n <= 0)
        return false;

    int x = (log2(n) / log2(3));
    return n == pow(3, x);
}
int main()
{
    std::cout << isPowerOfThree(243);
}
