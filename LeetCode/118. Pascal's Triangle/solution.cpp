#include <iostream>
#include <vector>
using namespace std;

int** cache;

int binom(int n, int k, int** cache)
{
    if (cache[n][k] != -1)
        return cache[n][k];

    if (k == 0 || k == n)
        return cache[n][k] = 1;

    cache[n][k] = binom(n - 1, k - 1, cache) + binom(n - 1, k, cache);
    return cache[n][k];
}

void init_cache(int n)
{
    cache = new int* [n + 1];

    for (size_t i = 0; i < n + 1; i++)
    {
        cache[i] = new int[n + 1];
    }

    for (size_t i = 0; i < n + 1; i++)
    {
        for (size_t j = 0; j < n + 1; j++)
        {
            cache[i][j] = -1;
        }
    }
}

void free_cache(int n)
{
    for (size_t i = 0; i < n + 1; i++)
    {
        delete[] cache[i];
    }
    delete[] cache;
}


vector<vector<int>> getRow(int rowIndex) {

    init_cache(rowIndex);
    vector<vector<int>> vec;

    for (size_t i = 0; i <= rowIndex; i++)
    {
        for (size_t j = 0; j <= i; j++)
        {
            binom(i, j, cache);
        }

    }

    for (size_t i = 0; i <= rowIndex; i++)
    {
        vector<int> row;
        for (size_t j = 0; j <= i; j++)
        {
            row.push_back(cache[i][j]);
        }
        vec.push_back(row);
    }

    for (size_t i = 0; i < vec.size(); i++)
    {
        for (size_t j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

    free_cache(rowIndex);
    return vec;
}

int main()
{

    getRow(12);

}
