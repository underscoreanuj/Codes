// non-iterative & non-recursive O(1) solution

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        return (n > 0 && 1162261467 % n == 0);
    }
};

// recursive solution

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        return n > 0 ? (n > 1 ? (n % 3 != 0 ? false : isPowerOfThree(n / 3)) : true) : false;
    }
};

// iterative solution

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n <= 0)
            return false;

        while (n > 1)
        {
            if ((n % 3) != 0)
                return false;
            n /= 3;
        }
        return true;
    }
};