#include <bits/stdc++.h>
using namespace std;

uint64_t binom(int n, int k, vector<vector<uint64_t>> &C)
{
    if (C[n][k] == -1)
        return C[n][k];

    return C[n][k] = binom(n - 1, k - 1, C) + binom(n - 1, k, C);
}

uint64_t uniquePaths(int m, int n)
{

    int N = n + m - 2;
    int K = min(n - 1, m - 1);

    vector<vector<uint64_t>> C(200, vector<uint64_t>(200, -1));

    for (int k = 1; k <= K; k++)
        C[0][k] = 0;
    for (int n = 0; n <= N; n++)
        C[n][0] = 1;

    cout << binom(30,15,C)<<endl;

    return binom(N,K,C);
}

int main()
{

    cout << uniquePaths(16,16) << endl;
    return 0;
}