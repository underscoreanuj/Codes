// iterative solution

class Solution
{
public:
    string convertToTitle(int n)
    {
        string result;

        while (n)
        {
            --n;
            result = char(n % 26 + 'A') + result;
            n /= 26;
        }

        return result;
    }
};

// recursive solution

class Solution
{
public:
    string convertToTitle(int n)
    {
        return n == 0 ? "" : convertToTitle((n - 1) / 26) + char((n - 1) % 26 + 'A');
    }
};