class Solution
{
public:
    int countPairs(vector<int> &deliciousness)
    {
        const int MOD = 1e9 + 7;
        int result = 0;
        int limit = 1 << 21;
        unordered_map<int, int> mem;

        for (int &d : deliciousness)
        {
            for (int x = 1; x <= limit; x <<= 1)
            {
                if (x < d)
                    continue;
                result += mem[x - d];
                result = (result >= MOD ? result - MOD : result);
            }
            ++mem[d];
        }

        return result;
    }
};