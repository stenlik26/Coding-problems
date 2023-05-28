#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isIsomorphic_util(string& s, string t)
{
    unordered_map<char, char> s_t;

    for (size_t i = 0; i < s.length(); i++)
    {
        if (s_t[s[i]] != 0 && s_t[s[i]] != t[i])
            return false;
        s_t[s[i]] = t[i];
    }

    return true;
}

bool isIsomorphic(string s, string t) {
    return isIsomorphic_util(s, t) && isIsomorphic_util(t, s);
}

int main()
{
    cout << isIsomorphic("badc", "baba") <<endl;
    cout << isIsomorphic("baba", "badc") <<endl;
    cout << isIsomorphic("paper", "title") <<endl;
}
