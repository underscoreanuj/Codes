class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int len = 0, i = 0, count = 0;
        string ct;

        while (i < chars.size())
        {
            count = 1;
            while (i + count < chars.size() && chars[i] == chars[i + count])
                ++count;

            chars[len++] = chars[i];
            i += count;

            if (count > 1)
            {
                ct = to_string(count);
                for (char &c : ct)
                    chars[len++] = c;
            }
        }

        return len;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();