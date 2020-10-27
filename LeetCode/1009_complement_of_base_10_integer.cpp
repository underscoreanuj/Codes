// efficient bit-mask approach

class Solution
{
public:
    int bitwiseComplement(int N)
    {
        if (N == 0)
            return 1;

        int mask = N;

        mask |= (mask >> 1);
        mask |= (mask >> 2);
        mask |= (mask >> 4);
        mask |= (mask >> 8);
        mask |= (mask >> 16);

        return N ^ mask;
    }
};

// simple bitwise flipping approach

class Solution
{
public:
    int bitwiseComplement(int N)
    {
        if (N == 0)
            return 1;

        int result = 0, i = 0;

        while (N)
        {
            if (N % 2 == 0)
                result += pow(2, i);
            N >>= 1;
            ++i;
        }

        return result;
    }
};

// bit mask approach

class Solution
{
public:
    int bitwiseComplement(int N)
    {
        int mask = 1;

        while (mask < N)
        {
            mask = (mask << 1) + 1;
        }

        return N ^ mask;
    }
};