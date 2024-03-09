#include <bits/stdc++.h>
using namespace std;

int getCommon(vector<int> &nums1, vector<int> &nums2)
{
    int a = 0;
    int b = 0;

    const int a_size = nums1.size();
    const int b_size = nums2.size();

    while (a < a_size && b < b_size)
    {
        const int val1 = nums1[a];
        const int val2 = nums2[b];

        if (val1 == val2)
            return val1;

        if (val1 > val2)
            ++b;
        else
            ++a;
    }

    return -1;
}

int main()
{

    cout << "Test" << endl;
    return 0;
}