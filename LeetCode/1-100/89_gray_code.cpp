// the idea is to use the following rule:
// when n=3, we can get the result based on n=2. 00,01,11,10 -> (000,001,011,010)[already present] (110,111,101,100) [to be found]

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> result;
        result.push_back(0);
        int cur_size = 0;

        for (long i = 0; i < n; ++i)
        {
            cur_size = result.size();
            for (int j = cur_size - 1; j >= 0; --j)
            {
                result.push_back(result[j] | 1 << i);
            }
        }

        return result;
    }
};

// alternative solution

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> result;
        n = powl(2, n);

        for (int i = 0; i < n; ++i)
            result.push_back((i ^ (i >> 1)));

        return result;
    }
};