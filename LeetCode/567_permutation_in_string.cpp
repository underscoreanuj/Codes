class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> MEM(128, 0);
        int window_size = s1.length(), count = 0, l = 0;

        for (char &c : s1)
            ++MEM[c];

        for (int r = 0; r < s2.length(); ++r)
        {
            if (--MEM[s2[r]] >= 0)
                ++count;
            if (count == window_size)
                return true;
            if (r - l + 1 == window_size && ++MEM[s2[l++]] > 0)
                --count;
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