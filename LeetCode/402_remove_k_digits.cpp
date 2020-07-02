class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        string res;
        for (char &n : num)
        {
            while (k > 0 && res.length() && res.back() > n)
            {
                res.pop_back();
                --k;
            }
            if (res.length() || n != '0')
                res += n;
        }

        while (res.length() && k--)
            res.pop_back();

        return res.length() ? res : "0";
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();