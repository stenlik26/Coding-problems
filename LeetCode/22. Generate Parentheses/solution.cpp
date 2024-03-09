#include <bits/stdc++.h>
using namespace std;

void rec_build(int n, int open, vector<string>& res, string current)
{
    if(n == 0)
    {
        res.push_back(current);
        return;
    }

    if(open == 0)
    {
        rec_build(n, 1, res, current + "(");
        return;
    }

    if(open != n)
        rec_build(n, open + 1, res, current + "(");

    rec_build(n - 1, open - 1, res, current + ")");
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    rec_build(n, 0, res, "");
    return res;
}

int main()
{

    generateParenthesis(6);
    return 0; 

}