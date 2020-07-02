class Solution
{
public:
    int countSplits(vector<int> &nums, long long int largestSum)
    {
        long long int count = 1, tmp_sum = 0;
        for (int &n : nums)
        {
            if (tmp_sum + n > largestSum)
            {
                ++count;
                tmp_sum = n;
            }
            else
                tmp_sum += n;
        }

        return count;
    }

    int splitArray(vector<int> &nums, int m)
    {
        long long int l = INT_MIN, r = 0, mid = 0;
        for (int &n : nums)
        {
            l = max(l, (long long int)n);
            r += n;
        }

        while (l < r)
        {
            mid = l + ((r - l) >> 1);

            if (countSplits(nums, mid) > m)
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();