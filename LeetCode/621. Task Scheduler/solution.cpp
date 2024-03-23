#include <bits/stdc++.h>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {

    vector<int> freq(26,0);

    for (size_t i = 0; i < tasks.size(); i++)
    {
        freq[tasks[i] - 'A']++;
    }
    sort(freq.begin(), freq.end()); 
    int interval = freq[25] - 1;
    int idle = interval * n;

    for (int i = 24; i >= 0; i--)
    {
        idle -= min(interval,freq[i]);
    }
    
    return idle < 0 ? tasks.size() : tasks.size() + idle;
}

int main()
{
    vector<char> t = {'A','A','A','B','B','B'};
    leastInterval(t, 2);
    return 0; 

}