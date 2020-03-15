/*
 *
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Amazon.
 * There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time. Given N, write a function that returns the number of unique ways you can climb the staircase. The order of the steps matters.
 * For example, if N is 4, then there are 5 unique ways:

    -----------------
    |   1, 1, 1, 1  |
    |   2, 1, 1     |
    |   1, 2, 1     |
    |   1, 1, 2     |
    |   2, 2        |
    -----------------

 *
 * What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a set of positive integers X? For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
 * 
 * 
 * Online Judge: https://leetcode.com/problems/climbing-stairs/
 * 
*/

// standard online judge solution
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (n == 3)
            return 3;

        n -= 3;
        int f = 2, s = 3;
        while (n--)
        {
            s = f + s;
            f = s - f;
        }

        return s;
    }
};

// generic solution which handles any number of steps

class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> steps = {1, 2};
        vector<int> tab(n + 1, 0);

        for (int i = 0; i < tab.size(); ++i)
        {
            for (int &s : steps)
            {
                tab[i] += i - s > 0 ? tab[i - s] : 0;
                tab[i] += i == s ? 1 : 0;
            }
        }

        return tab[n];
    }
};
