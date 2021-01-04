// linear solution with pointers

class Solution
{
public:
    int waysToSplit(vector<int> &nums)
    {
        int n = nums.size(), result = 0, j = 0, k = 0, MOD = 1e9 + 7;
        vector<int> preSum(n, 0);
        partial_sum(nums.begin(), nums.end(), preSum.begin());

        for (int i = 0; i < n - 2; ++i)
        {
            while (j <= i || (j < n - 1 && preSum[i] > preSum[j] - preSum[i]))
                ++j;
            while (k <= j || (k < n && preSum[k - 1] - preSum[i] <= preSum.back() - preSum[k - 1]))
                ++k;
            result += max(k - j - 1, 0);
            if (result >= MOD)
                result -= MOD;
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

// binary search based solution

class Solution
{
public:
    int waysToSplit(vector<int> &nums)
    {
        int n = nums.size(), result = 0, start = 0, end = 0, limit = 0, MOD = 1e9 + 7;
        vector<int> preSum(n, 0);
        partial_sum(nums.begin(), nums.end(), preSum.begin());

        for (int i = 0; i < n - 2; ++i)
        {
            limit = (preSum.back() - preSum[i]) >> 1;
            start = lower_bound(preSum.begin() + i + 1, preSum.end(), preSum[i] + preSum[i]) - preSum.begin();
            end = (upper_bound(preSum.begin() + start, preSum.end() - 1, preSum[i] + limit) - preSum.begin()) - 1;
            result += max(end - start + 1, 0);
            if (result >= MOD)
                result -= MOD;
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