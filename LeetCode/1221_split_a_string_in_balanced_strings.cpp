class Solution
{
public:
    int balancedStringSplit(string s)
    {
        int result = 0, count = 0;

        for (char &c : s)
        {
            count += (c == 'L') ? 1 : -1;
            if (count == 0)
                ++result;
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