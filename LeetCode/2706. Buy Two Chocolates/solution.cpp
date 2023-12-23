#include<iostream>
#include <string>
#include<vector>
#include<limits.h>

using namespace std;

int buyChoco(vector<int>& prices, int money) {
    int min_a = INT_MAX, min_b = INT_MAX;
    int leftover_money = money;
    for (size_t i = 0; i < prices.size(); i++)
    {
        if(min_a > prices[i])
        {
            min_b = min_a;
            min_a = prices[i];
        }
        else if(min_b > prices[i])
        {
            min_b = prices[i];
        }
    }
    leftover_money -= min_a + min_b;
    return (leftover_money >= 0) ? leftover_money : money;
}

int main()
{

    cout << "Test" << endl; 
    return 0; 

}