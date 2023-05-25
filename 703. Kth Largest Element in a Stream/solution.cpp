#include <iostream>
#include <vector>
using namespace std;

class KthLargest {
private:
    vector<int> nums;

    void swap_sort()
    {
        for (int i = nums.size() - 1; i > 0; i--)
        {
            if (nums[i] > nums[i - 1])
                swap(nums[i], nums[i - 1]);
        }
    }

    int k;

public:
    
    KthLargest(int k, vector<int>& nums) {

        this->k = k - 1;
        for (size_t i = 0; i < nums.size(); i++)
        {
            this->nums.push_back(nums[i]);
            swap_sort();
        }
    }

    int add(int val) {
        this->nums.push_back(val);
        swap_sort();
        return nums[k];
    }
};

int main()
{
    vector<int> init({ 4, 5, 8, 2 });
    KthLargest* kthLargest = new KthLargest(3, init);
    cout << kthLargest->add(3) << " = 4\n";   // return 4
    cout << kthLargest->add(5) << " = 5\n";   // return 5
    cout << kthLargest->add(10) << " = 5\n";  // return 5
    cout << kthLargest->add(9) << " = 8\n";   // return 8
    cout << kthLargest->add(4) << " = 8\n";  // return 8
}
