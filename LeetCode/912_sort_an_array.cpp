// count sort

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        int count[100001];
        memset(count, 0, sizeof(count));

        for (int &n : nums)
            ++count[n + 50000];

        int idx = 0;
        for (int i = 0; i < 100001; ++i)
        {
            if (count[i])
                for (int j = 0; j < count[i]; ++j)
                    nums[idx++] = i - 50000;
        }

        return nums;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();