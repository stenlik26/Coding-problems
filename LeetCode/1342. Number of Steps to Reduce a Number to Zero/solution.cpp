
// No1342.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int steps_rec_tail(int num, int res)
{
    if (num == 2)
        return res + 2;

    if (num % 2 == 0)
        return steps_rec_tail(num / 2, res + 1);
    else
        return steps_rec_tail(num - 1, res + 1);
}

int numberOfSteps(int num) {
    if (num == 0)
        return 0;
    if (num == 1)
        return 1;
    return steps_rec_tail(num, 0);
}

int main()
{
    std::cout << numberOfSteps(83962);
}
