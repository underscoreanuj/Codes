class Solution
{
public:
    int getMaximumGenerated(int n)
    {
        if (n <= 1)
            return n;
        int result = 0;
        vector<int> mem(n + 1, 0);
        mem[1] = 1;

        for (int i = 2; i <= n; ++i)
        {
            mem[i] = (i & 1) ? mem[i >> 1] + mem[(i >> 1) + 1] : mem[i >> 1];
            result = max(result, mem[i]);
        }

        return result;
    }
};