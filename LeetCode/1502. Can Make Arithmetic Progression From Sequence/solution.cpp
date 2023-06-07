class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
            vector<int> arr_sorted = arr;

    sort(arr_sorted.begin(), arr_sorted.end(), [](int a, int b) {return a < b; });

    int diff = arr_sorted[1] - arr_sorted[0];

    for (size_t i = 2; i < arr_sorted.size(); i++)
    {
        if (arr_sorted[i] - arr_sorted[i - 1] != diff)
            return false;
    }
    return true;
    }
};