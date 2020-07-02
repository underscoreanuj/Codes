// constatnt extra space solution

class Solution
{
public:
    string reverseWords(string s)
    {
        int l = 0, r = 0;

        while (r <= s.length())
        {
            if (s[r] == ' ' || r == s.length())
            {
                reverse(s.begin() + l, s.begin() + r);
                l = r + 1;
            }
            ++r;
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

// O(N) extra space solution

class Solution
{
public:
    string reverseWords(string s)
    {
        istringstream SS(s);
        string token;
        string result;

        while (getline(SS, token, ' '))
        {
            reverse(token.begin(), token.end());
            result += token + " ";
        }

        return result.substr(0, result.length() - 1);
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();