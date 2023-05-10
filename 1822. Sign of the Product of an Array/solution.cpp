class Solution {
public:
    int signFunc(long long x)
    {
        if(x>0)
            return 1;
        else 
            return x == 0 ? 0 : -1;
    }
    int arraySign(vector<int>& nums) {
    bool is_neg = false;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            return 0;
        if (signFunc(nums[i]) == -1)
        {
            if (is_neg)
                is_neg = false;
            else
                is_neg = true;
        }
    }
    return is_neg ? -1 : 1;
    }
};
