#include <bits/stdc++.h>
using namespace std;

int bagOfTokensScore(vector<int>& tokens, int power) {
    sort(tokens.begin(), tokens.end());

    int left = 0, right = tokens.size() - 1;

    int score = 0, max_score = 0;

    while(left <= right)
    {
        if(power >= tokens[left])
        {
            power -= tokens[left];
            left++;
            score++;
        }
        else if(score >= 1)
        {
            power += tokens[right];
            score--;
            right--;
        }
        else
        {
            right--;
        }

        max_score = max(max_score, score);
    }

    return max_score;
}

int main()
{

    cout << "Test" << endl; 
    return 0; 

}