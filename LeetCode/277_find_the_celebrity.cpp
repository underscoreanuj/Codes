// solved on: https://www.lintcode.com/problem/find-the-celebrity/description

// time: O(n), space: O(1) solution

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution
{
public:
    /**
     * @param n a party with n people
     * @return the celebrity's label or -1
     */
    int findCelebrity(int n)
    {
        // Write your code here
        int l = 0, r = n - 1, deg = 0;

        while (l < r)
        {
            if (knows(l, r))
                ++l;
            else
                --r;
        }

        for (int i = 0; i < n; ++i)
            if (i != l && knows(i, l) && !knows(l, i))
                ++deg;

        return deg == n - 1 ? l : -1;
    }
};

// time: O(n), space: O(n) solution, recursive

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution
{
public:
    /**
     * @param n a party with n people
     * @return the celebrity's label or -1
     */
    int findCelebrityUtil(int id)
    {
        if (id == 1)
            return 0;

        int cel = findCelebrityUtil(id - 1);

        if (cel == -1)
            return id - 1;

        if (knows(id - 1, cel))
            return cel;
        else if (cel, id - 1)
            return id - 1;

        return -1;
    }

    int findCelebrity(int n)
    {
        // Write your code here
        int l = findCelebrityUtil(n), deg = 0;
        if (l == -1)
            return -1;

        for (int i = 0; i < n; ++i)
            if (i != l && knows(i, l) && !knows(l, i))
                ++deg;

        return deg == n - 1 ? l : -1;
    }
};

// time: O(n^2), space: O(n) solution

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution
{
public:
    /**
     * @param n a party with n people
     * @return the celebrity's label or -1
     */
    int findCelebrity(int n)
    {
        // Write your code here
        vector<int> balance(n, 0);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (j != i && knows(i, j))
                {
                    --balance[i];
                    ++balance[j];
                }
            }
        }

        for (int i = 0; i < n; ++i)
            if (balance[i] == n - 1)
                return i;

        return -1;
    }
};