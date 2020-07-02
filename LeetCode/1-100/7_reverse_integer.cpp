class Solution
{
public:
    int reverse(int x)
    {
        long long int ret = 0;
        while (x)
        {
            if (abs((long)10 * ret) > INT_MAX)
                return 0;
            ret = 10 * ret + x % 10;
            x /= 10;
        }
        return ret;
    }
};