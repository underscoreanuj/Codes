class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        unordered_map<int, int> buckets;
        int bucket;

        if (t < 0 || k < 0)
            return false;

        for (int i = 0; i < nums.size(); ++i)
        {
            bucket = nums[i] / (1L * t + 1);

            if (nums[i] < 0)
                --bucket;
            if (buckets.count(bucket))
                return true;
            if ((buckets.count(bucket - 1) && 1L * nums[i] - buckets[bucket - 1] <= t) || (buckets.count(bucket + 1) && 1L * buckets[bucket + 1] - nums[i] <= t))
                return true;

            buckets[bucket] = nums[i];

            if (i >= k)
            {
                bucket = nums[i - k] / (1L * t + 1);
                if (nums[i - k] < 0)
                    --bucket;

                buckets.erase(bucket);
            }
        }

        return false;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();