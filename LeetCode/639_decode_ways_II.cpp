class Solution
{
public:
    int numDecodings(string s)
    {
        int MOD = 1e9 + 7, n = s.length(), result = 0, prev = 1, p_prev = 0;

        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '*')
            {
                result = (9 * prev) % MOD;
                if (i > 0)
                {
                    if (s[i - 1] == '1')
                        result += (9 * p_prev) % MOD;
                    if (s[i - 1] == '2')
                        result += (6 * p_prev) % MOD;
                    if (s[i - 1] == '*')
                        result += (15 * p_prev) % MOD;
                }
            }
            else
            {
                if (s[i] > '0')
                    result = prev;
                if (i > 0 && (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7')))
                    result += p_prev;
                if (i > 0 && s[i - 1] == '*')
                    result += (((s[i] < '7') ? 2 : 1) * p_prev) % MOD;
            }
            result %= MOD;
            p_prev = prev % MOD;
            prev = result % MOD;
            result = 0;
        }

        return prev;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();