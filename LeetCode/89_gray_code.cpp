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