// solution using KMP lps array

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int n = s.length();
        vector<int> lps(n, 0);
        int i = 1, len = 0;

        while (i < n)
        {
            if (s[i] == s[len])
                lps[i++] = ++len;
            else
            {
                if (len > 0)
                    len = lps[len - 1];
                else
                    lps[i++] = 0;
            }
        }

        return lps[n - 1] > 0 && n % (n - lps[n - 1]) == 0;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// simple solution
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        return (s + s).substr(1, 2 * s.length() - 2).find(s) != string::npos;
    }
};
