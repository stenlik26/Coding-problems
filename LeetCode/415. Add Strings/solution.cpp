#include <iostream>
#include <string>
using namespace std;

uint16_t to_num(const char& c)
{
    return c - '0';
}

string addStrings(string num1, string num2) {

    string res = "";

    bool carry = false;

    int i = 0;
    int j = 0;

    for (i = num1.size() - 1, j = num2.size() - 1; i >= 0 && j >= 0; i--, j--)
    {
        int total = to_num(num1[i]) + to_num(num2[j]) + carry;

        res = to_string(total % 10) + res;

        carry = total / 10;
    }

    while (i >= 0)
    {
        int total = to_num(num1[i]) + carry;

        res = to_string(total % 10) + res;

        carry = total / 10;

        i--;
    }

    while (j >= 0)
    {
        int total = to_num(num2[j]) + carry;

        res = to_string(total % 10) + res;

        carry = total / 10;

        j--;
    }

    if (carry)
        res = "1" + res;

    return res;
}

int main()
{
    cout << addStrings("123", "888") << endl;
}
