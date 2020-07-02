class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> mem(128, 0);

        for (char &c : magazine)
            ++mem[c];

        for (char &c : ransomNote)
        {
            if (mem[c] > 0)
                --mem[c];
            else
                return false;
        }

        return true;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();