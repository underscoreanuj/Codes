// O(1) space, O(n) time, no modification of nums

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0];
        int fast = nums[0];

        while (true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
                break;
        }

        slow = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();