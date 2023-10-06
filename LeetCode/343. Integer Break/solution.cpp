#include<iostream>
#include <string>
#include<vector>
#include <cmath>

using namespace std;

int integerBreak(int n) {

    uint32_t maxed_sum = 0;
    
    for (size_t i = 2; i <= n; i++)
    {
        uint32_t min = n / i;
        uint32_t ost = n % i;

        uint32_t current_sum = pow((min+1), ost) *  pow(min, (i-ost));

        if(current_sum > maxed_sum)
            maxed_sum = current_sum;
    }
    
    return maxed_sum;
}

int main()
{

    cout << integerBreak(7)<<endl;
    cout << integerBreak(8)<<endl;
    cout << integerBreak(9)<<endl;
    cout << integerBreak(10)<<endl;
    return 0; 

}