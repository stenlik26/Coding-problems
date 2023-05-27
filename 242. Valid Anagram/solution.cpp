#include <iostream>
#include <string>
using namespace std;

bool isAnagram(string s, string t) {

    if (s.length() != t.length())
        return false;

    int char_count_s[26] = {0};
    int char_count_t[26] = {0};

    for (size_t i = 0; i < s.length(); i++)
    {
        char_count_s[s[i] - 'a']++;
        char_count_t[t[i] - 'a']++;
    }

    for (size_t i = 0; i < 26; i++)
    {
        if (char_count_s[i] != char_count_t[i])
            return false;
    }

    return true;
}

int main()
{
    cout << isAnagram("rat", "car") << endl;
    cout << isAnagram("anagram", "nagaram") << endl;
}
