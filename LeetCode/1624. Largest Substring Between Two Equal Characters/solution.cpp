#include<iostream>
#include <string>
#include<vector>

using namespace std;

int maxLengthBetweenEqualCharacters(string s) {
    vector<int> chars(26, -1);
    int chars[26] = {-1};
    int max_len = -1;

    for (size_t i = 0; i < s.size(); i++)
    {
        if(chars[s[i] - 'a'] == -1)
            chars[s[i] - 'a'] = i;
        else
        {
            int candidate_diff = i - chars[s[i] - 'a'] - 1;
            if(candidate_diff > max_len)
                max_len = candidate_diff;
        }
    }

    return max_len;
}

int main()
{

    cout << maxLengthBetweenEqualCharacters("aa") << endl; 
    cout << maxLengthBetweenEqualCharacters("abca") << endl; 
    cout << maxLengthBetweenEqualCharacters("cbzxy") << endl; 
    cout << maxLengthBetweenEqualCharacters("bahhhhhhau") << endl; 
    return 0; 

}