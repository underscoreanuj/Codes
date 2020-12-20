class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int min1 = INT_MAX, min2 = INT_MAX;
        for (int &n : nums)
        {
            if (n <= min1)
                min1 = n;
            else if (n <= min2)
                min2 = n;
            else
                return true;
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