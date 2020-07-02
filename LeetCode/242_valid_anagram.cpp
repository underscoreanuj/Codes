class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        vector<int> Counts(26, 0);

        for (char c : s)
            ++Counts[c - 'a'];
        for (char c : t)
            --Counts[c - 'a'];
        for (int c : Counts)
            if (c != 0)
                return false;

        return true;
    }
};