class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<unsigned int> tab(target + 1, 0);
        tab[0] = 1;

        for (int i = 1; i <= target; ++i)
        {
            for (int &n : nums)
            {
                if (i >= n)
                    tab[i] += tab[i - n];
            }
        }

        return tab[target];
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();