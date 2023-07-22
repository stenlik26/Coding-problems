#include <iostream>

bool hasAlternatingBits(int n) {

    for (size_t i = 1; i <= 31; i++)
    {
        if ((1 << (i-1)) > n)
            break;

        bool bit1 = (bool)(n & (1 << i));
        bool bit2 = (bool)(n & (1 << (i - 1)));

        if (!(bit1 ^ bit2))
            return false;
    }
    return true;
}

int main()
{
    std::cout << hasAlternatingBits(5) << "\n";
    std::cout << hasAlternatingBits(7) << "\n";
    std::cout << hasAlternatingBits(11) << "\n";
}

