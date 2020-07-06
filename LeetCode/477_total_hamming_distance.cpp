class Solution
{
public:
    int totalHammingDistance(vector<int> &nums)
    {
        int result = 0, count = 0, n = nums.size();
        for (int i = 0; i < 32; ++i)
        {
            count = 0;
            for (int &n : nums)
                if (n & (1 << i))
                    ++count;
            result += count * (n - count);
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