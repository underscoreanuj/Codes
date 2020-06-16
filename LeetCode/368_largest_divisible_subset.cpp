class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        if (nums.size() == 0)
            return {};

        int n = nums.size(), pos = 0;
        sort(nums.begin(), nums.end());
        vector<int> tab(n, 1);
        vector<int> mem(n, -1);

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] % nums[j] == 0 && 1 + tab[j] > tab[i])
                {
                    tab[i] = 1 + tab[j];
                    mem[i] = j;
                    if (tab[pos] < tab[i])
                        pos = i;
                }
            }
        }

        vector<int> result;

        while (pos != -1)
        {
            result.emplace_back(nums[pos]);
            pos = mem[pos];
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