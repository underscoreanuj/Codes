class Solution
{
public:
    int numDecodings(string s)
    {
        if (s.length() == 0)
            return 0;
        int n = s.length();
        vector<int> MEM(n + 1, 0);
        MEM[n] = 1;

        for (int i = n - 1; i >= 0; --i)
        {
            if (s[i] != '0')
            {
                MEM[i] = MEM[i + 1];
                if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')))
                    MEM[i] += MEM[i + 2];
            }
            else
                MEM[i] = 0;
        }

        return MEM[0];
    }
};