class Solution
{
public:
    string toLowerCase(string str)
    {
        for (int i = 0; i < str.size(); ++i)
            str[i] = (str[i] >= 65 && str[i] <= 90) ? str[i] + 32 : str[i];

        return str;
    }
};