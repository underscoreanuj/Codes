class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        vector<string> op(numRows);

        int idx = 0;
        int f = 1;
        for (int i = 0; i < s.length(); ++i)
        {
            op[idx] += s[i];
            if (idx == numRows - 1)
                f = -1;
            if (idx == 0)
                f = 1;
            idx += f;
        }
        string ret;
        for (auto l : op)
            ret += l;

        return ret;
    }
};