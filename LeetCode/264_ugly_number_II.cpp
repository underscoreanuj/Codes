class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<long long int> mem = {1};
        int idx2 = 0, idx3 = 0, idx5 = 0;
        long long int tmp2 = 0, tmp3 = 0, tmp5 = 0, tmp = 0;

        while (mem.size() < n)
        {
            tmp2 = mem[idx2] * 2;
            tmp3 = mem[idx3] * 3;
            tmp5 = mem[idx5] * 5;

            tmp = min(tmp2, min(tmp3, tmp5));
            mem.emplace_back(tmp);

            if (tmp2 == tmp)
                ++idx2;
            if (tmp3 == tmp)
                ++idx3;
            if (tmp5 == tmp)
                ++idx5;
        }

        return mem.back();
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();