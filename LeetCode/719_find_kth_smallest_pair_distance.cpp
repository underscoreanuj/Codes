// binary search solution

class Solution
{
public:
    int countPairs(vector<int> &nums, int diff)
    {
        int count = 0, l = 0;
        for (int r = 1; r < nums.size(); ++r)
        {
            while (nums[r] - nums[l] > diff)
                ++l;
            count += r - l;
        }

        return count;
    }

    int smallestDistancePair(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int l = 0, r = nums[nums.size() - 1] - nums[0], mid = 0;

        while (l < r)
        {
            mid = l + ((r - l) >> 1);
            if (countPairs(nums, mid) < k)
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// O(N^2(logN)) solution (TLE)

class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        auto compare = [&nums](const pair<int, int> &o1, const pair<int, int> &o2) {
            return (abs(nums[o1.first] - nums[o1.second])) > (abs(nums[o2.first] - nums[o2.second]));
        };

        sort(nums.begin(), nums.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> PQ(compare);

        for (int i = 0; i < nums.size() - 1; ++i)
            PQ.push({i, i + 1});

        for (int i = 1; i < k; ++i)
        {
            auto e = PQ.top();
            PQ.pop();
            if (e.second + 1 < nums.size())
                PQ.push({e.first, e.second + 1});
        }

        return abs(nums[PQ.top().first] - nums[PQ.top().second]);
    }
};