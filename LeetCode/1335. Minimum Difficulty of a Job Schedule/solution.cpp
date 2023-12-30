#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int rec(vector<int>& job_diffc, int i, int d, vector<vector<int>>& dp)
{
    if(job_diffc.size() - i <= d)
        return INT_MAX;

    if(dp[i][d] != INT_MAX)
        return dp[i][d];

    if(i == job_diffc.size() - 1)
        return dp[i][d] = job_diffc[i];

    if(d == 0)
        return dp[i][d] = max(job_diffc[i], rec(job_diffc, i+1, d, dp));

    if(i == job_diffc.size() - 2)
        return dp[i][d] = job_diffc[i] + job_diffc[i+1];
        
    int current_sec_max = job_diffc[i];
    int res = INT_MAX;

    for (size_t j = i + 1; j < job_diffc.size(); j++)
    {
        int next_cut = rec(job_diffc, j, d - 1, dp);

        if(next_cut != INT_MAX)
            res = min(res, current_sec_max + next_cut);

        current_sec_max = max(current_sec_max, job_diffc[j]);
        
    }
    return dp[i][d] = res;
}


int minDifficulty(vector<int>& jobDifficulty, int d) {
    
    if(d > jobDifficulty.size())
        return -1;

    vector<vector<int>> dp(jobDifficulty.size(), vector<int>(d, INT_MAX));
    return rec(jobDifficulty, 0, d - 1, dp);
}

int main()
{
    vector<int> test = {6,5,4,3,2,1};
    cout << minDifficulty(test, 2) << endl;

    vector<int> test2 = {186,398,479,206,885,423,805,112,925,656,16,932,740,292,671,360};
    cout << minDifficulty(test2, 4) << endl;

    vector<int> test3 = {1,1,1};
    cout << minDifficulty(test3, 3) << endl;

    vector<int> test4 = {9,9,9};
    cout << minDifficulty(test4, 4) << endl;

    return 0; 

}
