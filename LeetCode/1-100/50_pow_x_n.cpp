class Solution
{
public:
    double getPow(double x, long n)
    {
        if (x == 0 || x == 1)
            return x;
        double ret = 1;
        while (n)
        {
            if (n & 1)
                ret *= x;
            x *= x;
            n >>= 1;
        }

        return ret;
    }

    double myPow(double x, long n)
    {
        if (n < 0)
            return 1.0 / getPow(x, -n);
        return getPow(x, n);
    }
};