#include<iostream>
#include <string>
#include<vector>

using namespace std;

int minSteps(string s, string t) {
    int s_map[26] = {0};
    int t_map[26] = {0};

    for (size_t i = 0; i < s.length(); i++)
    {
        s_map[s[i] - 'a']++;
        t_map[t[i] - 'a']++;
    }

    int res = 0;
    for (size_t i = 0; i < 26; i++)
    {
        if(s_map[i] == t_map[i])
            continue;
            
        res += abs(s_map[i] - t_map[i]);
    }
    return res / 2;
}

int main()
{

    cout << minSteps("bab", "aba") << endl; 
    return 0; 

}