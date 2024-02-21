#include<iostream>
#include <string>
#include<vector>

using namespace std;

int same_bit_length_check(const int& l, const int& r)
{
    int l_first_one = -1;
    int r_first_one = -1;

    for (int i = 31; i >= 0; i--)
    {
        if(l_first_one == -1 && (l & (1 << i)))
            l_first_one = i;
        
        if(r_first_one == -1 && (r & (1 << i)))
            r_first_one = i;
    }

    return (l_first_one == r_first_one) ? l_first_one : -1;
}

int rangeBitwiseAnd(int left, int right) {
    
    if(left == right)
        return left;

    if((left == 0 || right == 0))
        return 0;
    
    int first_one = same_bit_length_check(left,right);

    if(first_one == -1)
        return 0;

    int res = 0;

    int range = right - left + 1;

    for (int i = first_one; i >= 0; i--)
    {
        int cur_mainp = (1 << i);
        if((left & cur_mainp) && (right & cur_mainp) && (range <= cur_mainp))
        {
            res |= (1 << i);
        }
    }
    return res;
}

int main()
{
    //cout << rangeBitwiseAnd(2147483647,2147483647);
    cout << rangeBitwiseAnd(5,7)<<endl;
    return 0; 

}