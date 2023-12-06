#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Noraml recursion
int numberOfMatches_normal(int n)
{
    if (n == 1)
        return 0;
    if (n % 2 == 0)
        return n / 2 + numberOfMatches(n / 2);
    else
        return 1 + (n - 1) / 2 + numberOfMatches((n - 1) / 2);
}

//Tail recursion
const int matches_tail(int n, int total)
{
    if (n == 1)
        return total;
    if (n % 2 == 0)
        return matches_tail(n / 2, total + n / 2);
    else
        return matches_tail((n - 1) / 2, total + 1 + (n - 1) / 2);
}

int numberOfMatches(int n)
{
    return matches_tail(n,0);
}

int main()
{

    cout << "Test" << endl;
    return 0;
}