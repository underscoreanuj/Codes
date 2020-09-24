// XOR approach

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        char result = 0;
        for (char &c : s)
            result ^= c;
        for (char &c : t)
            result ^= c;

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// difference approach

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        int result = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            result -= s[i];
            result += t[i];
        }

        result += t[t.length() - 1];

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();