class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int len = secret.size(), cow_count = 0, bull_count = 0;
        vector<int> mem(128, 0);

        for (int i = 0; i < len; ++i)
        {
            if (secret[i] == guess[i])
                ++bull_count;
            else
            {
                if (mem[secret[i]]++ < 0)
                    ++cow_count;
                if (mem[guess[i]]-- > 0)
                    ++cow_count;
            }
        }

        return to_string(bull_count) + "A" + to_string(cow_count) + "B";
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();