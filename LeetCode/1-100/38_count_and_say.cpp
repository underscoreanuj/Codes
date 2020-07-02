class Solution
{
public:
    string countAndSayUtil(string num)
    {
        string ret;
        int ct = 1;
        for (int i = 0; i < num.length(); ++i)
        {
            ct = 1;
            while (i + 1 < num.length() && num[i] == num[i + 1])
            {
                ++ct;
                ++i;
            }
            ret += to_string(ct) + string(1, num[i]);
        }

        return ret;
    }

    string countAndSay(int n)
    {
        if (n == 1)
            return "1";

        string s = "1";
        while (--n)
            s = countAndSayUtil(s);

        return s;
    }
};