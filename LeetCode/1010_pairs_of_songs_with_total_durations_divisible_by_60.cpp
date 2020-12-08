class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        vector<int> mem(60, 0);
        int count = 0, idx = -1;

        for (int &t : time)
        {
            idx = (60 - (t % 60)) % 60;
            if (mem[idx])
                count += mem[idx];
            ++mem[t % 60];
        }

        return count;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();