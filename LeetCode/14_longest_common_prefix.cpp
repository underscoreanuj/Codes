class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
            return "";
        if (strs.size() == 1)
            return strs[0];

        for (int p = 0;; ++p)
        {
            if (p >= strs[0].size())
                return strs[0];
            char c = strs[0][p];
            for (int i = 1; i < strs.size(); ++i)
            {
                if (p >= strs[i].size())
                    return strs[i];
                if (strs[i][p] != c)
                    return strs[i].substr(0, p);
            }
        }

        return "";
    }
};