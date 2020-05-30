class Solution
{
public:
    int climbStairs(int n)
    { // simply fibonacci numbers
        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        int f = 1, s = 2, ret = 0;
        for (int i = 0; i < n - 2; ++i)
        {
            ret = f + s;
            f = s;
            s = ret;
        }

        return ret;
    }
};