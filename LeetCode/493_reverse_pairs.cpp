// BIT based solution

class Solution
{
    vector<int> f;

public:
    void update(int x)
    {
        while (x < f.size())
        {
            ++f[x];
            x += (x & -x);
        }
    }

    int get(int x)
    {
        int res = 0;
        while (x > 0)
        {
            res += f[x];
            x -= (x & -x);
        }
        return res;
    }

    int reversePairs(vector<int> &nums)
    {
        int result = 0, n = nums.size(), l_pos = 0, pos = 0;
        f = vector<int>(n + 1, 0);

        vector<int> sorted_nums(nums.begin(), nums.end());
        sort(sorted_nums.begin(), sorted_nums.end());

        for (int i = nums.size() - 1; i >= 0; --i)
        {
            pos = lower_bound(sorted_nums.begin(), sorted_nums.end(), nums[i]) - sorted_nums.begin();
            l_pos = lower_bound(sorted_nums.begin(), sorted_nums.end(), (int)((((long)nums[i]) + 1) >> 1)) - sorted_nums.begin();
            result += get(l_pos);
            update(pos + 1);
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

// merge sort based solution

class Solution
{
    typedef vector<int>::iterator it;

public:
    void reversePairsUtil(it l, it r, int &result)
    {
        if (r - l <= 1)
            return;

        it m = l + ((r - l) >> 1);

        reversePairsUtil(l, m, result);
        reversePairsUtil(m, r, result);

        it j = m;
        for (it i = l; i < m; ++i)
        {
            while (j < r && (long)(*i) > 2 * (long)(*j))
                ++j;
            result += (j - m);
        }

        inplace_merge(l, m, r);
    }

    int reversePairs(vector<int> &nums)
    {
        int result = 0;
        reversePairsUtil(nums.begin(), nums.end(), result);

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();