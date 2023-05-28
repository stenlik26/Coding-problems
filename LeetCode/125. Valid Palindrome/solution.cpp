#include <iostream>
#include <string>
using namespace std;

string& remove_non_alphanum(string& n, const string& from)
{
    for (size_t i = 0; i < from.size(); i++)
    {
        if (isalnum(from[i]))
            n += from[i];
    }
    return n;
}

bool isPalindrome(string s) {
    string new_s = "";

    remove_non_alphanum(new_s, s);
    for (size_t i = 0; i < new_s.size() / 2; i++)
    {
        if (tolower(new_s[i]) != tolower(new_s[new_s.size() - i - 1]))
            return false;
    }
    return true;
}

int main()
{
    string test1 = "A man, a plan, a canal: Panama";
    string test2 = "race a car";
    string test3 = ".,";

    std::cout << test1 << " " << isPalindrome(test1) << std::endl;
    std::cout << test2 << " " << isPalindrome(test2) << std::endl;
    std::cout << test3 << " " << isPalindrome(test3) << std::endl;
}
