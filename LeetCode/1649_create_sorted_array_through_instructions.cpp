class Solution
{
    vector<int> f;

public:
    void update(int x)
    {
        while (x < f.size())
        {
            f[x]++;
            x += (x & -x);
        }
    }

    int get(int x)
    {
        int res = 0;
        while (x > 0)
        {
            res += f[x];
            x -= (x & -x);
        }
        return res;
    }

    int createSortedArray(vector<int> &instructions)
    {
        int result = 0, MOD = 1e9 + 7, n = instructions.size();
        f = vector<int>(100001, 0);

        for (int i = 0; i < n; ++i)
        {
            result = (result + min(get(instructions[i] - 1), (i - get(instructions[i])))) % MOD;
            update(instructions[i]);
        }

        return result;
    }
};