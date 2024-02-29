#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <limits.h>

using namespace std;

struct current_flight_info
{
    int node;
    int price_from_start;
    int stops_from_start;
};

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    // Node -> {..., (to, price), ...}
    unordered_map<int, vector<pair<int, int>>> graph;
    int prices_to_reach[101];

    for (size_t i = 0; i < 101; i++)
    {
        prices_to_reach[i] = INT_MAX;
    }
    

    for (size_t i = 0; i < flights.size(); i++)
    {
        graph[flights[i][0]].push_back({flights[i][1], flights[i][2]});
    }

    int stops = 0;
    int min_price = INT_MAX;
    
    queue<current_flight_info> nodes_to_try;
    unordered_set<int> visited; 

    nodes_to_try.push({src,0,0});

    while(!nodes_to_try.empty())
    {
        current_flight_info info = nodes_to_try.front();
        nodes_to_try.pop();

        if(info.stops_from_start - 1 > k)
            continue;

        if(info.price_from_start < prices_to_reach[info.node])
            prices_to_reach[info.node] = info.price_from_start;
        else
            continue;

        if(info.node == dst && info.price_from_start < min_price)
            min_price = info.price_from_start;

        for (size_t i = 0; i < graph[info.node].size(); i++)
        {
            current_flight_info new_info = info;
            new_info.node = graph[info.node][i].first;
            new_info.price_from_start += graph[info.node][i].second;
            new_info.stops_from_start++;

            nodes_to_try.push(new_info);
        }
        
    }

    if(min_price != INT_MAX)
        return min_price;
    else 
        return -1;
}

int main()
{
    int n = 4, src = 0, dst = 3, k = 1;
    vector<vector<int>> flights = {{0,1,1},{0,2,5},{1,2,1},{2,3,1}};

    cout << findCheapestPrice(n, flights, src, dst, k) << endl;

    return 0;
}
