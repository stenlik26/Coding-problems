#include<iostream>
#include <string>
#include<vector>

using namespace std;

bool makeEqual(vector<string>& words) {

    int map[26] = {0};
    int words_count = words.size();

    for (vector<string>::iterator word = words.begin(); word != words.end(); ++word)
    {   
        int wrd_size = (*word).size();
        for (int i = 0; i < wrd_size; i++)
        {
            map[(*word)[i] - 'a']++;
        }
        
    }
    
    for (int i = 0; i < 26; i++)
    {
        if(map[i] % words_count != 0)
            return false;
    }
    return true;
} 

int main()
{
    vector<string> test =  {"a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","abb","abb","abb","abb","abb","abb","abb","abb","abb","abb","abb","abb","abb","abb","abb","abb","abb","abb","abb","abb"};
    cout << makeEqual(test) << endl; 
    return 0; 

}