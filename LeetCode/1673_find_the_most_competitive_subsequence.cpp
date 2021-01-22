class Solution
{
public:
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {
        int n = nums.size(), j = 0;
        vector<int> result(k);

        for (int i = 0; i < n; ++i)
        {
            while (j && result[j - 1] > nums[i] && j + n - i - 1 >= k)
                --j;
            if (j < k)
                result[j++] = nums[i];
        }

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();