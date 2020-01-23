class Solution
{
public:
    int myAtoi(string str)
    {
        int ind = 0;
        bool neg = false;
        while (str[ind] == ' ')
            ++ind;
        if (str[ind] == '-')
        {
            neg = true;
            ++ind;
        }
        if (str[ind] == '+')
        {
            if (neg)
                return 0;
            neg = false;
            ++ind;
        }
        if (!isdigit(str[ind]))
            return 0;

        long ret = 0;
        while (isdigit(str[ind]))
        {
            if (!neg && ret * 10 + (str[ind] - '0') >= INT_MAX)
                return INT_MAX;
            if (neg && ret * -10 - (str[ind] - '0') <= INT_MIN)
                return INT_MIN;

            ret = ret * 10 + str[ind] - '0';
            ++ind;
        }

        return neg ? ret * -1 : ret;
    }
};