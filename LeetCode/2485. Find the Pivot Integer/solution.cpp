#include <bits/stdc++.h>
using namespace std;

uint32_t one_to_n(int n)
{
    return n*(n+1)/2;
}

uint32_t n_to_m(int n, int m)
{
    return one_to_n(m) - one_to_n(n) + n;
}

int pivotInteger(int n) {
    int left = 1;
    int right = n;

    while(left <= right)
    {
        uint32_t mid = (left + right)/2;

        uint32_t x = n_to_m(1, mid);
        uint32_t y = n_to_m(mid, n);

        cout << x << " " << y << endl;
        if(x == y)
            return mid;
        else if(x > y)
            right = mid;
        else
        {
            if(left != mid)
                left = mid;
            else
                return -1;
        }
    }
    return -1;
}

int main()
{

    pivotInteger(4);
    return 0; 

}