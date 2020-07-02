class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1[0] == '0' || num2[0] == '0')
            return "0";

        string M(num1.size() + num2.size(), '0');
        int val = 0, mul = 0;
        for (int i = num1.size() - 1; i >= 0; --i)
        {
            val = num1[i] - '0';
            for (int j = num2.size() - 1; j >= 0; --j)
            {
                mul = val * (num2[j] - '0') + (M[i + j + 1] - '0');
                M[i + j + 1] = mul % 10 + '0';
                M[i + j] += mul / 10;
            }
        }

        for (int i = 0; i < M.length(); ++i)
        {
            if (M[i] != '0')
                return M.substr(i);
        }

        return M;
    }
};