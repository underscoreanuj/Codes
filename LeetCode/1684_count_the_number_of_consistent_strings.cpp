// bit manipulation based solution (faster)

class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        int result = 0;
        bool flag = true;
        int mem = 0;
        for (char &c : allowed)
            mem ^= (1 << (c - 'a'));

        for (string &word : words)
        {
            flag = true;
            for (char &c : word)
            {
                if ((mem & (1 << (c - 'a'))) == 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
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

// simple solution

class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        int result = 0;
        bool flag = true;
        unordered_set<char> mem(allowed.begin(), allowed.end());

        for (string &word : words)
        {
            flag = true;
            for (char &c : word)
            {
                if (!mem.count(c))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
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