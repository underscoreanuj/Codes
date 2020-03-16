class Solution
{
    vector<int> nums;

public:
    Solution(vector<int> &nums)
    {
        this->nums = nums;
    }

    int pick(int target)
    {
        int count = 0, idx = -1;
        for (int i = 0; i < this->nums.size(); ++i)
        {
            if (this->nums[i] == target)
            {
                ++count;
                if (1 + (rand() % count) == 1)
                    idx = i;
            }
        }
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
