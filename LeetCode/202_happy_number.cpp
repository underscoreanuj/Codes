// O(1) solution  (think of it like detecting a cycle in a linked list)

class Solution
{
public:
    int getSumOfSquareOfDigits(int n)
    {
        int res = 0;
        while (n)
        {
            res += pow(n % 10, 2);
            n /= 10;
        }

        return res;
    }

    bool isHappy(int n)
    {
        if (n == 1)
            return true;

        int slow = n;
        int fast = n;

        while (true)
        {
            slow = getSumOfSquareOfDigits(slow);
            if (slow == 1)
                return true;

            fast = getSumOfSquareOfDigits(getSumOfSquareOfDigits(fast));
            if (fast == 1)
                return true;

            if (fast == slow)
                return false;
        }

        return true;
    }
};

// first approach

class Solution
{
public:
    int getSumOfSquareOfDigits(int n)
    {
        int res = 0;
        while (n)
        {
            res += pow(n % 10, 2);
            n /= 10;
        }

        return res;
    }

    bool isHappy(int n)
    {
        unordered_set<int> seen;

        while (true)
        {
            if (n == 1)
                return true;

            n = getSumOfSquareOfDigits(n);

            if (seen.count(n))
                return false;

            seen.insert(n);
        }

        return false;
    }
};