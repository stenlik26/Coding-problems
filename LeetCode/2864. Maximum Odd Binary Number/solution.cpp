#include <bits/stdc++.h>
using namespace std;

string maximumOddBinaryNumber(string s) {
    int ones = 0, zeros = 0;

    for (size_t i = 0; i < s.size(); i++)
        if(s[i]=='1')
            ones++;

    zeros = s.size() - ones;
    
    string res = "";

    for (size_t i = 0; i < ones - 1; i++)
        res += "1";

    for (size_t i = 0; i < zeros; i++)
        res += "0";
    
    res += "1";

    return res;
}

int main()
{

    cout << "Test" << endl; 
    return 0; 

}