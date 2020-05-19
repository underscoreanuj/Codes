// a more efficient solution

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int result = 0, l = 0;
        vector<int> MEM(128, 0);

        for (int r = 0; r < s.length(); ++r)
        {
            if (MEM[s[r]] > 0)
            {
                while (s[l] != s[r])
                    --MEM[s[l++]];
                --MEM[s[l++]];
            }
            ++MEM[s[r]];
            result = max(result, r - l + 1);
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

// normal solution
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.length() == 0)
            return 0;

        unordered_set<char> H;
        int i = 0, j = 0, n = s.length(), max_len = 0;

        while (i < n)
        {
            if (H.find(s[i]) == H.end())
            {
                H.insert(s[i]);
                ++i;
                max_len = max(max_len, i - j);
            }
            else
            {
                H.erase(s[j]);
                ++j;
            }
        }

        return max_len;
    }
};