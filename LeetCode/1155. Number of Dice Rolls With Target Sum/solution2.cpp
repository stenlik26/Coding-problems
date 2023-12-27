#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

const uint32_t modulo = 1000000007;
const uint32_t rec_mem(int n, int k, int target, vector<vector<long>> &cache)
{
    if (target <= 0 || (n == 1 && target > k))
    {
        cache[n][target] = 0;
        return 0;
    }

    if (n == 1)
    {
        cache[n][target] = 1;
        return 1;
    }

    if(cache[n][target] != -1)
        return cache[n][target] % modulo;

    uint64_t sum = 0;
    for (int i = 1; i <= k; i++)
    {
        if (target - i <= 0)
            break;

        if (cache[n - 1][target - i] == -1)
        {
            cache[n - 1][target - i] = rec_mem(n - 1, k, target - i, cache);
        }

        if (cache[n - 1][target - i] != -1)
            sum += cache[n - 1][target - i];
    }
    return sum % modulo;
}

int numRollsToTarget(int n, int k, int target)
{
    vector<vector<long>> cache(32, vector<long>(1002, -1));

    return rec_mem(n, k, target, cache);
}

int main()
{

    //cout << numRollsToTarget(1, 6, 3) << endl;
    //cout << numRollsToTarget(2, 6, 7) << endl;
    //cout << numRollsToTarget(3, 6, 7) << endl;
    cout << numRollsToTarget(30, 30, 500) << endl;
    return 0;
}