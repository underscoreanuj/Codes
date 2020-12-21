class Solution
{
public:
    int smallestRangeI(vector<int> &A, int K)
    {
        int max_ele = INT_MIN, min_ele = INT_MAX;
        for (int &a : A)
        {
            max_ele = max(max_ele, a);
            min_ele = min(min_ele, a);
        }

        return max(max_ele - min_ele - 2 * K, 0);
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();