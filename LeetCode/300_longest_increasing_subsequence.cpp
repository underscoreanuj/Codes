// O(nlogn) solution

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        vector<int> tab(nums.size(), 0);
        int len = 1, pos = 0;
        tab[0] = nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            if (tab[len - 1] < nums[i])
            {
                tab[len++] = nums[i];
            }
            else
            {
                pos = lower_bound(tab.begin(), tab.begin() + len, nums[i]) - tab.begin();
                tab[pos] = nums[i];
            }
        }

        return len;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// O(n^2) solution

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        int result = 1;
        vector<int> tab(nums.size(), 1);

        for (int i = 1; i < nums.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                    tab[i] = max(tab[i], tab[j] + 1);
            }
            result = max(result, tab[i]);
        }

        return result;
    }
};