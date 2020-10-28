class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> result;
        if (nums.size() == 0)
            return result;

        int start_idx = 0, end_idx = 0;

        for (int i = 1; i < nums.size(); ++i)
        {
            if ((long)nums[i] - (long)nums[i - 1] > 1)
            {
                if (start_idx == end_idx)
                    result.emplace_back(to_string(nums[start_idx]));
                else
                    result.emplace_back(to_string(nums[start_idx]) + "->" + to_string(nums[end_idx]));

                start_idx = i;
            }
            end_idx = i;
        }

        if (start_idx == end_idx)
            result.emplace_back(to_string(nums[start_idx]));
        else
            result.emplace_back(to_string(nums[start_idx]) + "->" + to_string(nums[end_idx]));

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();