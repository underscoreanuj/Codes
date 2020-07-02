class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        long l = 1, r = num, mid = 0, sq = 0;
        while (l <= r)
        {
            mid = l + ((r - l) >> 1);
            sq = mid * mid;

            if (sq == num)
                return true;
            else if (sq < num)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return false;
    }
};