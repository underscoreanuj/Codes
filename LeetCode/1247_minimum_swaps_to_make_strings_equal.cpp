class Solution
{
public:
    int minimumSwap(string s1, string s2)
    {
        int xy = 0, yx = 0;
        for (int i = 0; i < s1.length(); ++i)
        {
            if (s1[i] != s2[i])
            {
                if (s1[i] == 'x')
                    ++xy;
                if (s1[i] == 'y')
                    ++yx;
            }
        }

        if ((xy + yx) & 1)
            return -1;

        return (xy >> 1) + (yx >> 1) + 2 * (xy % 2);
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();