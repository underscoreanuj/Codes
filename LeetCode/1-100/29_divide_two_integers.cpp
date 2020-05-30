class Solution
{
public:
    int divide(long long int dividend, long long int divisor)
    {
        bool neg = (dividend < 0) ^ (divisor < 0);

        long long int ret = 0, t = 1, d = 0;
        long long int dvd = labs(dividend);
        long long int dvs = labs(divisor);

        while (dvd >= dvs)
        {
            t = 1;
            d = dvs;
            while (d << 1 < dvd)
            {
                d = d << 1;
                t = t << 1;
            }
            dvd -= d;
            ret += t;
        }

        ret = neg ? -ret : ret;
        ret = ret > INT_MAX ? INT_MAX : ret;
        ret = ret < INT_MIN ? INT_MIN : ret;

        return ret;
    }
};