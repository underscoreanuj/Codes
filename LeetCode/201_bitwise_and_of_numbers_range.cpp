// iterative solution

class Solution
{
public:
    int rangeBitwiseAnd(int m, int n)
    {
        if (m == 0 || m == n)
            return m;

        if ((n / m) >= 2)
            return 0;

        int i = 0;
        while (m != n)
        {
            m >>= 1;
            n >>= 1;
            ++i;
        }

        return (m << i);
    }
};

// recursive solution

class Solution
{
public:
    int rangeBitwiseAnd(int m, int n)
    {
        return m != n ? (rangeBitwiseAnd(m >> 1, n >> 1) << 1) : m;
    }
};