// O(n)
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int cur = 0, count = 0;
        for (int &n : nums)
        {
            if (count == 0)
                cur = n;
            count += cur == n ? 1 : -1;
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