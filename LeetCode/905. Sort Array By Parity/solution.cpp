#include <iostream>
#include <vector>
using namespace std;

const bool is_even(int x)
{
    return x % 2 == 0;
}

vector<int> sortArrayByParity(vector<int>& nums) 
{
    vector<int> new_array(nums.size());

    int front = 0, back = nums.size() - 1;

    for (size_t i = 0; i < nums.size(); i++)
    {
        if (is_even(nums[i]))
            new_array[front++] = nums[i];
        else
            new_array[back--] = nums[i];
    }
    return new_array;
}

void test_case(vector<int>& test)
{
    vector<int> res = sortArrayByParity(test);

    for (auto i = res.begin(); i < res.end(); ++i)
    {
        std::cout << *i << " ";
    }
    cout << "\n";
    
}

int main()
{
    vector<int> input1 = { 3,1,2,4 };
    vector<int> input2 = { 3,2,4,5,6,7 };
    vector<int> input3 = { 3,2,1,1,1,1 };
    vector<int> input4 = { 0,1,2 };
    
    test_case(input1);
    test_case(input2);
    test_case(input3);
    test_case(input4);
}
