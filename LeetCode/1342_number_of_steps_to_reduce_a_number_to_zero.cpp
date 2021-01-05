// counting bit solution
// __builtin_clz returns number of leading zeros: so __builtin_clz(1) returns 31, hence we subtract it with 31 and not 32 since the last value of num , i.e. 1 will only require to be subtrcted

class Solution
{
public:
    int numberOfSteps(int num)
    {
        return num ? __builtin_popcount(num) + 31 - __builtin_clz(num) : 0;
    }
};

// simple approach

class Solution
{
public:
    int numberOfSteps(int num)
    {
        int x = num, result = 0;

        while (x)
        {
            x = x & 1 ? (x - 1) : (x >> 1);
            ++result;
        }

        return result;
    }
};