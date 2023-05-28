#include <iostream>
#include <string>
using namespace std;
int map_digits(char c)
{
    switch (c)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }
    return 0;
}

int romanToInt(string s) {
    int len = s.length();

    size_t result = 0;

    for (size_t i = 0; i < len; i++)
    {
        int num = map_digits(s[i]);

        if ((s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) ||
            (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) ||
            (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M')))
        {
            result += map_digits(s[i + 1]) - num;
            i++;
            continue;
        }
        result += num;
    }
    return result;
}

int main()
{
    string t1 = "III";
    string t2 = "LVIII";
    string t3 = "MCMXCIV";

    std::cout << romanToInt(t1) << std::endl;
    std::cout << romanToInt(t2) << std::endl;
    std::cout << romanToInt(t3) << std::endl;
}
