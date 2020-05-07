// O(n)
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int cur = nums[0], count = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            count += nums[i] == cur ? 1 : -1;
            if (count == 0)
            {
                cur = nums[i];
                count = 1;
            }
        }

        return cur;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// O(n)
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        nth_element(nums.begin(), nums.begin() + (nums.size() >> 1), nums.end());
        return nums[nums.size() >> 1];
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// O(n)

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> mem;
        for (int &n : nums)
        {
            ++mem[n];
            if (mem[n] > floor(nums.size() >> 1))
                return n;
        }

        return -1;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();