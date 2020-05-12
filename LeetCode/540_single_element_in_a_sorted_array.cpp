// time: O(logn), space: O(1) solution

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1, mid = 0;

        while (l < r)
        {
            mid = l + ((r - l) >> 1);

            if (mid & 1)
            { // mid is odd
                if (mid > 0 && nums[mid] == nums[mid - 1])
                    l = mid + 1;
                else
                    r = mid;
            }
            else
            { // mid is even
                if (mid + 1 < nums.size() && nums[mid] == nums[mid + 1])
                    l = mid + 1;
                else
                    r = mid;
            }
        }

        return nums[l];
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// time: O(n), space: O(1) solution

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int res = 0;
        for (auto n : nums)
            res ^= n;

        return res;
    }
};