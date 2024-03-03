#include <bits/stdc++.h>
using namespace std;

int rec(const vector<int>& cost, int n, vector<int>& dp)
{
    if(n >= cost.size())
        return 0;

    if(dp[n] != -1)
        return dp[n];
    else
        return dp[n] = cost[n] + min(rec(cost, n+1, dp), rec(cost, n+2, dp));
}

int minCostClimbingStairs(vector<int>& cost) {

    vector<int> dp(cost.size(), -1);

    return min(rec(cost, 0, dp), rec(cost, 1, dp));
}

int main()
{
    vector<int> t = {10,15,20};
    cout << minCostClimbingStairs(t)<<endl;
    return 0; 

}