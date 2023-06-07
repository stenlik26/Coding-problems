#include <iostream>
using namespace std;

int hammingDistance(int x, int y) {
    int diff = 0;

    for (size_t i = 0; i <= 31; i++)
    {
        diff += (bool)((x & (1 << i)) ^ (y & (1 << i)));
    }

    return diff;
}

int main()
{
    cout << hammingDistance(1, 4) << endl;
    cout << hammingDistance(3, 1) << endl;
}
