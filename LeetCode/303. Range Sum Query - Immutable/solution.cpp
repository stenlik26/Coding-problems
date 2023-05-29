#include <iostream>
#include <vector>
using namespace std;

class NumArray {
private:
    vector<int> n;
public:
    NumArray(vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); i++)
        {
            n.push_back(nums[i]);
        }
    }

    int sumRange(int left, int right) {
        if (left > right)
            return 0;

        long sum = 0;
        for (size_t i = left; i <= right; i++)
        {
            sum += n[i];
        }
        return sum;
    }
};

int main()
{
    vector<int> init = { -2, 0, 3, -5, 2, -1 };
    NumArray* n = new NumArray(init);

    cout << n->sumRange(0, 2) << endl;
    cout << n->sumRange(2, 5) << endl;
    cout << n->sumRange(0, 5) << endl;
}
