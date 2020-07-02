class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> result, MEM(128, 0);
        int window_size = p.length(), count = 0;
        for (char &c : p)
            ++MEM[c];

        int l = 0;
        for (int r = 0; r < s.length(); ++r)
        {
            if (--MEM[s[r]] >= 0)
                ++count;
            if (count == window_size)
                result.emplace_back(l);
            if (r - l + 1 == window_size && ++MEM[s[l++]] > 0)
                --count;
        }

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();