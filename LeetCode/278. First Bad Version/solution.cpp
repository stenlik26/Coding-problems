#include <iostream>

bool isBadVersion(int version)
{
    return version >= 4;
}

int firstBadVersion(int n) {

    if (n == 1)
        return isBadVersion(n);

    int left = 0;
    int right = n;

    long mid = (left + right) / 2;

    while (left < right)
    {
        mid = (left + right) / 2;
        if (isBadVersion(mid))
        {
            if (isBadVersion(mid - 1))
                right = mid - 1;
            else
                return mid;
        }
        else
        {
            if (isBadVersion(mid + 1))
                return mid + 1;
            else
                left = mid + 1;
        }
    }
    
    return mid;
}

int main()
{
    std::cout << firstBadVersion(5);
}
