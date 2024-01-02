#include<iostream>
#include <string>
#include<vector>
#include<algorithm>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int satisfied = 0;

    int g_i = 0;
    int s_i = 0;

    const int g_size = g.size();
    const int s_size = s.size();

    while(g_i < g_size && s_i < s_size)
    {
        if(s[s_i] >= g[g_i])
        {
            satisfied++;
            g_i++;
        }
        s_i++;
    } 

    return satisfied;
}

int main()
{

    cout << "Test" << endl; 
    return 0; 

}