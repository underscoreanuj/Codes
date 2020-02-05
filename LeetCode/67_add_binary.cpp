class Solution
{
public:
    string addBinary(string a, string b)
    {
        if (a.length() == 0)
            return b;
        if (b.length() == 0)
            return a;
        if (a.length() < b.length())
            return addBinary(b, a);

        string ret(a.length() + 1, '0');
        int i = a.length() - 1, j = b.length() - 1;
        int val = 0, carry = 0;
        while (i >= 0)
        {
            val = (a[i] - '0') + (j >= 0 ? b[j] - '0' : 0) + carry;
            carry = val / 2;
            ret[i + 1] = val % 2 + '0';
            --i;
            --j;
        }
        if (carry)
        {
            ret[0] = '1';
            return ret;
        }
        return ret.substr(1, a.length());
    }
};