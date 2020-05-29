class Solution
{
public:
    bool isValid(string sub_ip)
    {
        int num = stoi(sub_ip);
        if (sub_ip.length() > 1 && sub_ip[0] == '0')
            return false;
        return num <= 255 && num >= 0;
    }

    void restoreIpAddressesUtil(string &s, vector<string> &result, string sol, int start = 0, int count = 0)
    {
        if (count == 4 && start == s.length())
        {
            result.emplace_back(sol);
            return;
        }
        if (count > 4 || s.length() - start > (4 - count) * 3 || s.length() - start < (4 - count))
            return;

        string subWord;
        int limit = (start + 3 < s.length() ? 3 : s.length() - start);

        for (int len = 1; len <= limit; ++len)
        {
            subWord = s.substr(start, len);
            if (isValid(subWord))
            {
                restoreIpAddressesUtil(s, result, sol + (count ? "." : "") + subWord, start + len, count + 1);
            }
        }
    }

    vector<string> restoreIpAddresses(string s)
    {
        vector<string> result;
        string sol = "";
        restoreIpAddressesUtil(s, result, sol);

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();