#include<iostream>
#include <string>
#include<vector>

using namespace std;

int maxScore(string s) {
    
    int a_score = (s[0]=='0') ? 1 : 0;
    int b_score = 0;

    int max_score = 0;

    for (size_t i = 1; i < s.size(); i++)
    {
        if(s[i] == '1')
            b_score++;
    }

    max_score = b_score + a_score;
    
    for (size_t i = 1; i < s.size() - 1; i++)
    {
        if(s[i] == '1')
            b_score--;
        else
            a_score++;

        max_score = std::max(max_score, a_score + b_score);
    }
    
    return max_score;
}

int main()
{

    cout << maxScore("011101") << endl; 
    //cout << maxScore("00111") << endl; 
   // cout << maxScore("1111") << endl; 
    return 0; 

}