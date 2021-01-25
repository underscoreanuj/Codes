class Solution
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        if (k == 0)
            return true;
        int last_idx = -k - 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 1)
            {
                if (i - last_idx <= k)
                    return false;
                last_idx = i;
            }
        }

        return true;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();