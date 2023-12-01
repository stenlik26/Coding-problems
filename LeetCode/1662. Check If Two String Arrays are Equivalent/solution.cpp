#include<iostream>
#include <string>
#include<vector>

using namespace std;

const bool check_eq(const char* s1, const char* s2)
{
    if(*s1 == '\0' && *s2 == '\0')
        return true;
    
    if((*s1 == '\0' && *s2 != '\0') || (*s1 != '\0' && *s2 == '\0'))
        return false;
    
    if(*s1 != *s2)
        return false;
    
    return check_eq(s1 + 1, s2 + 1);
}

bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {

    if(word1.empty() || word2.empty())
        return word1.empty() && word2.empty();

    string w1 = word1[0];
    string w2 = word2[0];

    for (size_t i = 1; i < word1.size(); i++)
        w1.append(word1[i]);

    for (size_t i = 1; i < word2.size(); i++)
        w2.append(word2[i]);
    
    return check_eq(w1.c_str(), w2.c_str());
}

int main()
{

    cout << check_eq("Test", "Test") << endl;
    cout << check_eq("Test7", "Test2") << endl;
    cout << check_eq("Test7", "Tes") << endl;
    return 0; 

}