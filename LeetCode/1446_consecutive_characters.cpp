class Solution
{
public:
    int maxPower(string s)
    {
        int result = INT_MIN, len = 1;
        char cur = s[0];

        for (int i = 1; i < s.length(); ++i)
        {
            if (s[i] == cur)
                ++len;
            else
            {
                result = max(result, len);
                len = 1;
                cur = s[i];
            }
        }

        return max(result, len);
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();