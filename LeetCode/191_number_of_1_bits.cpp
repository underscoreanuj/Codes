// class Solution
// {
// public:
//     int hammingWeight(uint32_t n)
//     {
//         return __builtin_popcount(n);
//     }
// };

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        if (n == 0)
            return 0;

        int ct = 1;
        while (n & (n - 1))
        {
            n = n & (n - 1);
            ++ct;
        }

        return ct;
    }
};