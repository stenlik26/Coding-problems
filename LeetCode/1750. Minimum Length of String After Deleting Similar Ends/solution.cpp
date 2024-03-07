#include <bits/stdc++.h>
using namespace std;

int min_len(string s, int l, int r)
{
    if(l > r || r < 0)
        return 0;

    if(l == r)
        return 1;

    if(s[l] != s[r])
        return r - l + 1;

    if(l + 1 == r)
        return 0;

    while(l < r && s[l] == s[l+1])
        l++;
    
    while(r > 0 && s[r] == s[r-1])
        r--;

    return min_len(s, l + 1, r - 1);
}

int minimumLength(string s) {
    return min_len(s, 0, s.size() - 1);
}

int main()
{

    cout << minimumLength("bbbbbbbbbbbbbbbbbbb") << endl; 
    return 0; 

}