class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        if (num1.length() < num2.length())
            return addStrings(num2, num1);
        // num1 is always larger or equal in size to num2
        string result(num1.size() + 1, '0');
        int i = num1.size() - 1, sum = 0;

        for (int j = num2.size() - 1; j >= 0; --j)
        {
            sum = (num1[i] - '0') + (num2[j] - '0') + (result[i + 1] - '0');
            result[i + 1] = sum % 10 + '0';
            result[i] += sum / 10;
            --i;
        }

        while (i >= 0)
        {
            sum = (result[i + 1] - '0') + (num1[i] - '0');
            result[i + 1] = sum % 10 + '0';
            result[i] += sum / 10;
            --i;
        }

        return result[0] == '0' ? result.substr(1, result.length() - 1) : result;
    }
};