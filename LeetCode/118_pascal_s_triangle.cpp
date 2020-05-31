class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        if (numRows == 0)
            return {};

        vector<vector<int>> result;

        for (int i = 1; i <= numRows; ++i)
        {
            vector<int> res(i, 0);
            result.emplace_back(res);
        }

        result[0][0] = 1;

        for (int i = 1; i < numRows; ++i)
        {
            for (int j = 0; j < result[i].size(); ++j)
            {
                if (j == 0)
                    result[i][j] = result[i - 1][j];
                else if (j == result[i].size() - 1)
                    result[i][j] = result[i - 1][j - 1];
                else
                    result[i][j] = result[i - 1][j] + result[i - 1][j - 1];
            }
        }

        return result;
    }
};