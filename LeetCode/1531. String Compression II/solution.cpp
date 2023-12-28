#include<iostream>
#include <string>
#include<vector>
#include<limits.h>
#include<unordered_map>

using namespace std;

int get_digits(int count)
{
    if(count <= 1)
        return 1;
    else if(count <= 9)
        return 2;
    else if(count <= 99)
        return 3;
    return 4;
}


int rec_help(string& s, int i, int k, vector<vector<int>>& dp)
{
    if(k < 0) return INT_MAX;
    if(i >= s.size()) return 0;
    if(s.size() - i <= k) return 0;
    if(dp[i][k] != INT_MAX) return dp[i][k];

    unordered_map<char,int> freq;

    int min_len = INT_MAX;
    int max_freq = 0;
    for (size_t j = i; j < s.size(); j++)
    {
        max_freq = max(max_freq, ++freq[s[j]]);

        int encode_len = get_digits(max_freq);

        int del_count = (j - i + 1) - max_freq;

        int next_len = rec_help(s, j + 1, k - del_count, dp);

        if(next_len == INT_MAX)
            continue;
        
        min_len = min(min_len, encode_len + next_len);
    }
    return dp[i][k] = min_len;
}


int getLengthOfOptimalCompression(string s, int k) {
    vector<vector<int>> dp(s.size(), vector<int>(k+1, INT_MAX));
    return rec_help(s, 0, k, dp);
}

int main()
{

    cout << getLengthOfOptimalCompression("aaabcccd", 2)<< endl; 
    cout << getLengthOfOptimalCompression("aabbaa", 2)<< endl; 
    cout << getLengthOfOptimalCompression("aaaaaaaaaaa", 0)<< endl; 
    return 0; 

}