class Solution
{
public:
    int minSteps(string s, string t)
    {
        int count = t.length();
        vector<int> mem(26, 0);

        for (char c : s)
            ++mem[c - 'a'];

        for (char c : t)
        {
            if (mem[c - 'a'] > 0)
            {
                --mem[c - 'a'];
                --count;
            }
        }

        return count;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();