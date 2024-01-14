#include<iostream>
#include <string>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

bool compare_vectors(vector<int>& vec1, vector<int>& vec2)
{
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    for (size_t i = 0; i < vec1.size(); i++)
    {
        if(vec1[i] != vec2[i])
            return false;
    }

    return true;
}

bool closeStrings(string word1, string word2) {
    
    if(word1.size() != word2.size())
        return false;

    int word1_freq[26] = {0};
    int word2_freq[26] = {0};

    vector<int> word1_set (26,0);
    vector<int> word2_set (26,0);

    for (size_t i = 0; i < word1.size(); i++)
    {
        word1_freq[word1[i] - 'a']++;
        word2_freq[word2[i] - 'a']++;
    }
    
    for (size_t i = 0; i < 26; i++)
    {
        if(word1_freq[i] == 0 && word2_freq[i] == 0)
            continue;

        if((word1_freq[i] != 0 && word2_freq[i] == 0) || (word1_freq[i] == 0 && word2_freq[i] != 0))
            return false;

        word1_set.push_back(word1_freq[i]);
        word2_set.push_back(word2_freq[i]);
    }


    return compare_vectors(word1_set, word2_set);
}

void test_case(string str1, string str2, bool res)
{
    cout << closeStrings(str1, str2) << "; Should be - " << res << endl;
}

int main()
{
    test_case("abc", "bca", true); 
    test_case("a", "aa", false); 
    test_case("cabbba", "abbccc", true); 
    test_case("ssx", "uau", false); 
    test_case("aaabbbbccddeeeeefffff", "aaaaabbcccdddeeeeffff", false);
    test_case("uiuiiuuiuuuuuuwiwuuwiiiiuuuuwwiwuuu", "rppprrpurrrrrurrrurprprprprpuprruur", false);
    return 0; 

}