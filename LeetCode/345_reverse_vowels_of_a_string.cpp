class Solution
{
public:
    bool isVowel(char &c)
    {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
    string reverseVowels(string s)
    {
        int l = 0, r = s.length() - 1;
        while (l < r)
        {
            if (isVowel(s[l]) && isVowel(s[r]))
                swap(s[l++], s[r--]);
            if (!isVowel(s[l]))
                ++l;
            if (!isVowel(s[r]))
                --r;
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