class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        unordered_set<char> mem(J.begin(), J.end());
        int count = 0;

        for (char &c : S)
            if (mem.count(c))
                ++count;

        return count;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();