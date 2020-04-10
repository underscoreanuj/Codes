class Solution
{
public:
    string processEmail(string s)
    {
        string result = "";

        int i = 0;
        while (i < s.length())
        {
            if (s[i] == '@')
            {
                result += s.substr(i);
                break;
            }
            if (s[i] == '+')
            {
                while (s[i] != '@')
                    ++i;
            }
            else if (s[i] == '.')
                ++i;
            else
                result += s[i++];
        }

        return result;
    }

    int numUniqueEmails(vector<string> &emails)
    {
        unordered_set<string> emailSet;

        for (string &e : emails)
        {
            emailSet.insert(processEmail(e));
        }

        return emailSet.size();
    }
};

// reduces submission time
auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();