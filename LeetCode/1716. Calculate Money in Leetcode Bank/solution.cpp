#include<iostream>
#include <string>
#include<vector>

using namespace std;

const int sum_to_n(int n)
{
    return (n * (n+1)) / 2;
}

int totalMoney(int n) {
    int full_weeks = n / 7;
    int non_full_weeks = n % 7;
    
    uint32_t current_total = 0;

    if(full_weeks != 0)
        current_total += 28 * full_weeks + 7 * sum_to_n(full_weeks - 1);

    current_total += full_weeks * non_full_weeks + sum_to_n(non_full_weeks);
    
    return current_total;
}

int main()
{

 //cout << totalMoney(4) << endl; 
 //cout << totalMoney(10) << endl; 
 //cout << totalMoney(20) << endl; 
 cout << totalMoney(26) << endl; 
 return 0; 

}