#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_vowel(char c)
{    
    if(c >= 'a')
        c = c - 32;

    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

bool halvesAreAlike(string s)
{
    int half = s.size() / 2;

    int first_c = 0;
    int second_c = 0;

    for (size_t i = 0; i < half; i++)
    {
        if(is_vowel(s[i]))
            first_c++;
    }

    for (size_t i = half; i < s.size(); i++)
    {
        if(is_vowel(s[i]))
            second_c++;
    }
    
    return first_c == second_c;
}

int main()
{
    cout << halvesAreAlike("textbook") << endl;
    return 0;
}