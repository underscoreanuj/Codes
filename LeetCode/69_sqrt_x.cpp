// class Solution
// {
// public:
//     int mySqrt(int x)
//     {
//         if (x == 0)
//             return 0;
//         if (x <= 3)
//             return 1;

//         long long int r = x;
//         while (r > x / r)
//             r = (r + x / r) >> 1;

//         return r;
//     }
// };

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
            return 0;
        if (x <= 3)
            return 1;

        int l = 1, r = x, mid = 0;
        while (l <= r)
        {
            mid = l + ((r - l) >> 1);
            if (mid == x / mid)
                return mid;
            else if (mid < x / mid)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return r;
    }
};