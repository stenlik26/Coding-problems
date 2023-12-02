#include<iostream>
#include <string>
#include<vector>

using namespace std;


const bool can_be_constructed(const string& word, vector<int> chars_count_s)
{
    for (size_t i = 0; i < word.size(); i++)
    {
        chars_count_s[word[i] - 'a']--;
        if(chars_count_s[word[i] - 'a'] < 0)
            return false;
    }
    return true;
    
}

int countCharacters(vector<string>& words, string chars) 
{
    int res_count = 0;
    vector<int> chars_count(26,0);

    for (size_t i = 0; i < chars.size(); i++)
    {
        chars_count[chars[i] - 'a']++; 
    }

    for (size_t i = 0; i < words.size(); i++)
    {
        if(can_be_constructed(words[i], chars_count))
        {
            cout << words[i]<<endl;
            res_count += words[i].size();
        }
    }
    return res_count;
}

int main()
{

    vector<string> words = {"cat","bt","hat","tree"};
    string chars = "atach";

    cout << countCharacters(words, chars)<<endl;
    return 0; 

}