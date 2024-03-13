#include <bits/stdc++.h>
using namespace std;

void custom_sort(string& s, int order[26])
{
    for (size_t i = 0; i < s.size(); i++)
    {
        int k = i;
        for (size_t j = i+1; j < s.size(); j++)
        {
            if(order[s[j]-'a'] < order[s[k]-'a'])
                k = j;
        }
        if(k != i)
            std::swap(s[i], s[k]);
        
    }
}

string customSortString(string order, string s)
{
    int order_arr[26] = {0};
    
    for (size_t i = 0; i < 26; i++)
        order_arr[i] = 999;

    for (size_t i = 0; i < order.size(); i++)
    {
        order_arr[order[i] - 'a'] = i+1;
    }
    custom_sort(s, order_arr);
    return s;
}

int main()
{
    cout << customSortString("cba", "abcdex") << endl;
    return 0;
}