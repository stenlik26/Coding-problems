#include <iostream>
#include <string>
using namespace std;

bool is_prefix(const char* word, const char* pref)
{
    if (strlen(word) < strlen(pref))
        return false;

    while (*word != '\0' && *pref != '\0')
    {
        if (*word != *pref)
            return false;
        word++;
        pref++;
    }
    return *pref == '\0';
}

int strStr(string haystack, string needle) {
    const char* haystack_c = haystack.c_str();
    const char* needle_c = needle.c_str();

    int i = 0;

    while (*haystack_c != '\0')
    {
        if (is_prefix(haystack_c, needle_c))
            return i;

        haystack_c++;
        i++;
    }
    return -1;
}

int main()
{
    cout << strStr("sadbutsad", "sad") << endl;
    cout << strStr("leetcode", "letto") << endl;
}
