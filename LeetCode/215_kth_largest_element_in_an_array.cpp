// randomized partition based solution

class Solution
{
public:
    int partition(vector<int> &nums, int l, int r)
    {
        swap(nums[l], nums[l + (rand() % (r - l + 1))]);
        int pivot = nums[l];
        int j = l + 1;
        for (int i = l + 1; i <= r; ++i)
        {
            if (nums[i] >= pivot)
                swap(nums[i], nums[j++]);
        }
        swap(nums[l], nums[j - 1]);

        return j - 1;
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        int l = 0, r = nums.size() - 1, p = 0;
        while (true)
        {
            p = partition(nums, l, r);
            if (p == k - 1)
                return nums[p];
            else if (p > k - 1)
                r = p - 1;
            else
                l = p + 1;
        }
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// nth_element solution     (can also use partial_sort)

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return nums[k - 1];
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// priority queue solution      (can also use multiset)

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> PQ;
        for (int &n : nums)
        {
            if (PQ.size() < k)
                PQ.push(n);
            else if (n > PQ.top())
            {
                PQ.pop();
                PQ.push(n);
            }
        }

        return PQ.top();
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();