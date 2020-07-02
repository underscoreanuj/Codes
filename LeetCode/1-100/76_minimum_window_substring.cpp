class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.length() < t.length())
            return "";

        unordered_map<char, int> mem;
        for (char &c : t)
            ++mem[c];

        int l = 0, min_len = INT_MAX, start = -1, window = t.length();
        for (int r = 0; r < s.length(); ++r)
        {
            if (mem.count(s[r]))
            {
                --mem[s[r]];
                if (mem[s[r]] >= 0)
                    --window;
            }
            while (window == 0)
            {
                if (min_len > r - l)
                {
                    min_len = r - l;
                    start = l;
                }
                if (mem.count(s[l]))
                {
                    ++mem[s[l]];
                    if (mem[s[l]] > 0)
                        ++window;
                }
                ++l;
            }
        }

        if (start == -1)
            return "";

        return s.substr(start, min_len + 1);
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();