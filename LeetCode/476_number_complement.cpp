// a better approach
// (find a number with all bits as 1 untill the left most set bit of num,
// xor it with num to get the result, eg: num = 5(101) ^ (111) = 2(010))

class Solution
{
public:
    int findComplement(int num)
    {
        int bitmask = 1;
        while (bitmask < num)
            bitmask = (bitmask << 1) + 1;

        return bitmask ^ num;
    }
};

// normal approach

class Solution
{
public:
    int findComplement(int num)
    {
        if (num == 0)
            return 1;
        int result = 0, rem = 0, power = 0;
        while (num)
        {
            rem = num % 2;
            if (rem == 0)
                result += pow(2, power);

            num /= 2;
            ++power;
        }

        return result;
    }
};