// O(nlogn) solution (better overall performance for the test cases)

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        int result = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            if (binary_search(nums.begin() + i + 1, nums.end(), nums[i] + k))
                ++result;
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

// O(n) solution

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        int result = 0;
        unordered_map<int, vector<int>> mem;
        unordered_set<int> seen;

        for (int i = 0; i < nums.size(); ++i)
        {
            mem[nums[i]].emplace_back(i);
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (!seen.count(nums[i]))
            {
                if (k == 0)
                {
                    if (mem[nums[i]].size() > 1)
                        ++result;
                }
                else
                {
                    if (mem.count(nums[i] + k))
                        ++result;
                }
            }

            seen.insert(nums[i]);
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