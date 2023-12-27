#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

const uint32_t modulo = 1000000007;
const uint32_t rec_mem(int n, int k, int target, unordered_map<string, int>& cache)
{
    if(target <= 0 || (n==1 && target > k))
        return 0;

    if (n == 1)
        return 1;

    uint64_t sum = 0;
    for (size_t i = 1; i <= k; i++)
    {
        if(target - i <= 0)
            break;
        
        string key = to_string(n-1) + ":" + to_string(target-i);
        if(cache.find(key) == cache.end())
        {
            uint64_t res = rec_mem(n-1,k,target - i, cache);

            if(res != 0) 
                cache[key] = res;
        }
        sum += cache[key];
    }
    return sum % modulo;
}

int numRollsToTarget(int n, int k, int target)
{
    unordered_map<string,int> cache;

    return rec_mem(n,k,target, cache);
}

int main()
{

    //cout << numRollsToTarget(1, 6, 3) << endl;
    //cout << numRollsToTarget(2, 6, 7) << endl;
    //cout << numRollsToTarget(3, 6, 7) << endl;
    cout << numRollsToTarget(30, 30, 500) << endl;
    return 0;
}