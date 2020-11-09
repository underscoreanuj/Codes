class Solution
{
public:
    int minCostToMoveChips(vector<int> &position)
    {
        int count_odd = 0, count_even = 0;

        for (int &p : position)
        {
            if (p & 1)
                ++count_odd;
            else
                ++count_even;
        }

        return min(count_odd, count_even);
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();