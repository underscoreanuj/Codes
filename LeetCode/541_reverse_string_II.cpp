class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int limit = 0;
        for (int i = 0; i < s.length(); i += k + k)
        {
            limit = i + k <= s.length() ? i + k : s.length();
            reverse(s.begin() + i, s.begin() + limit);
        }

        return s;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();