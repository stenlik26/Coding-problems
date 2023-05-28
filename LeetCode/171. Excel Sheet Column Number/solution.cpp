#include <iostream>
#include <string>
using namespace std;

int titleToNumber(string columnTitle) 
{
    int total = 0;
    const size_t len = columnTitle.length();

    for (size_t i = 0; i < len; i++)
    {
        total += (int)(columnTitle[i] - 64) * pow(26, len - i - 1);
    }
    return total;
}

int main()
{
    cout << "AB: " << titleToNumber("AB") << endl;
    cout << "A: " << titleToNumber("A") << endl;
    cout << "ZY: " << titleToNumber("ZY") << endl;
    cout << "AAA: " << titleToNumber("AAA") << endl;
}
