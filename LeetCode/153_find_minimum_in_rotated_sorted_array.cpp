class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums[nums.size() - 1] > nums[0])
            return nums[0];

        int l = 0, r = nums.size() - 1, mid = 0;

        while (l < r)
        {
            mid = l + ((r - l) >> 1);

            if (nums[mid] < nums[0])
                r = mid;
            else
                l = mid + 1;
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