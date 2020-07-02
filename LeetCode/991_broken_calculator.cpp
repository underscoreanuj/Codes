class Solution
{
public:
    int brokenCalc(int X, int Y)
    {
        int result = 0;

        while (Y > X)
        {
            if (~Y & 1)
                Y >>= 1;
            else
                ++Y;
            ++result;
        }

        return result + (X - Y);
    }
};