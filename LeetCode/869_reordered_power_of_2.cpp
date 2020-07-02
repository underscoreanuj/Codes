// time: O(logN^2) solution

class Solution
{
public:
    int hash(int N)
    {
        int result = 0;
        while (N)
        {
            result += pow(10, N % 10);
            N /= 10;
        }

        return result;
    }

    bool reorderedPowerOf2(int N)
    {
        int H = hash(N);

        for (int i = 0; i < 32; ++i)
            if (hash(1 << i) == H)
                return true;

        return false;
    }
};