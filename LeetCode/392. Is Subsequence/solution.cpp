#include <iostream>
#include <iostream>
#include <string>
using namespace std;

bool is_sub_seq(const char* s, const char* t)
{
    if (*s == '\0')
        return true;

    if (*t == '\0')
        return false;

    if (*s == *t)
        return is_sub_seq(s + 1, t + 1);
    else
        return is_sub_seq(s, t + 1);
}

bool isSubsequence(string s, string t) {
    return is_sub_seq(s.c_str(), t.c_str());
}

int main()
{
    cout << isSubsequence("abc", "ahbgdc") << endl;
    cout << isSubsequence("axc", "ahbgdc") << endl;
}
