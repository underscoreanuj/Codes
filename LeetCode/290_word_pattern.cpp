// better solution

class Solution
{
public:
    bool wordPattern(string pattern, string str)
    {
        unordered_map<string, int> mem;

        vector<string> split;
        istringstream S(str);
        string tmp;
        while (getline(S, tmp, ' '))
        {
            split.emplace_back(tmp);
        }

        if (split.size() != pattern.size())
            return false;

        for (int i = 0; i < pattern.length(); ++i)
        {
            tmp = "p_" + string(1, pattern[i]);
            if (!mem.count(tmp))
                mem[tmp] = i;

            if (!mem.count(split[i]))
                mem[split[i]] = i;

            if (mem[tmp] != mem[split[i]])
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

// simple solution

class Solution
{
public:
    bool wordPattern(string pattern, string str)
    {
        unordered_map<char, string> mem;
        unordered_set<string> seen;

        vector<string> split;
        istringstream S(str);
        string tmp;
        while (getline(S, tmp, ' '))
        {
            split.emplace_back(tmp);
        }

        if (split.size() != pattern.size())
            return false;

        for (int i = 0; i < pattern.length(); ++i)
        {
            if (mem.count(pattern[i]) && mem[pattern[i]] != split[i])
                return false;
            if (!mem.count(pattern[i]) && seen.count(split[i]))
                return false;
            mem[pattern[i]] = split[i];
            seen.insert(split[i]);
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