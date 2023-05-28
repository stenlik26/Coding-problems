class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int vec_size = nums.size();
        int numsc = (vec_size * (vec_size + 1)) / 2;
        for(auto i = nums.begin(); i != nums.end(); i++)
        {
            numsc -= *i;
        }
        return numsc;
    }
};
