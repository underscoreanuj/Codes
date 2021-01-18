// O(n) approach using unordered_map

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        int result = 0;
        unordered_map<int, int> mem;

        for (int &n : nums)
        {
            if (mem[k - n] > 0)
            {
                ++result;
                --mem[k - n];
            }
            else
                ++mem[n];
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

// O(nlogn) approach using sorting and two pointer approach

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1, result = 0, sum = 0;

        while (l < r)
        {
            sum = nums[l] + nums[r];
            if (sum == k)
            {
                ++result;
                ++l;
                --r;
            }
            else if (sum < k)
                ++l;
            else
                --r;
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