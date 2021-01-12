// O(n^2) approach besides the naive approach which uses two loops // gives TLE

class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        vector<int> result(nums.size(), 0);
        multiset<int> tab;

        for (int i = nums.size() - 1; i >= 0; --i)
        {
            result[i] = distance(tab.begin(), tab.lower_bound(nums[i]));
            tab.insert(nums[i]);
        }

        return result;
    }
};

// merge sort based approach O(nlogn)

class Solution
{
    typedef vector<pair<int, int>>::iterator it;

public:
    void countSmallerUtil(it l, it r, vector<int> &result)
    {
        if (r - l <= 1)
            return;

        it m = l + ((r - l) >> 1);

        countSmallerUtil(l, m, result);
        countSmallerUtil(m, r, result);

        it j = m;
        for (it i = l; i < m; ++i)
        {
            while (j < r && (*j) < (*i))
                ++j;
            result[i->second] += (j - m);
        }

        inplace_merge(l, m, r);
    }

    vector<int> countSmaller(vector<int> &nums)
    {
        vector<int> result(nums.size(), 0);
        vector<pair<int, int>> mem;
        for (int i = 0; i < nums.size(); ++i)
            mem.emplace_back(nums[i], i);

        countSmallerUtil(mem.begin(), mem.end(), result);

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// BIT based approach O(nlogn) best approach

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

    vector<int> countSmaller(vector<int> &nums)
    {
        f = vector<int>(20002, 0); // to take into account -ve numbers
        vector<int> result(nums.size(), 0);
        int n = nums.size();

        for (int i = n - 1; i >= 0; --i)
        {
            result[i] = get(9999 + nums[i]); // to take into account -ve numbers
            update(10000 + nums[i]);         // to take into account -ve numbers
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
