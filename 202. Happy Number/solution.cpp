#include <iostream>
#include <unordered_set>
bool isHappyRec(int n, std::unordered_set<int>& set)
{
    if (n == 1)
        return true;

    if (set.find(n) != set.end())
        return false;

    size_t new_num = 0;

    set.insert(n);

    while (n != 0)
    {
        new_num += (n % 10) * (n % 10);
        n /= 10;
    }

    return isHappyRec(new_num, set);
}

bool isHappy(int n) {
    std::unordered_set<int> set;

    return isHappyRec(n, set);
}

int main()
{
    std::cout << isHappy(19) << std::endl;
    std::cout << isHappy(2) << std::endl;
}
