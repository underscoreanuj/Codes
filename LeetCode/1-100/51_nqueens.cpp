class Solution
{
public:
    vector<vector<string>> solutions;

    vector<string> getBoard(vector<int> &qPos)
    {
        vector<string> ret(qPos.size(), string(qPos.size(), '.'));
        int ind = 0;
        for (int i = 0; i < qPos.size(); ++i)
        {
            ret[ind++][qPos[i]] = 'Q';
        }

        return ret;
    }

    bool isValid(vector<int> &qPos, int val, int col)
    {
        for (int i = 0; i < col; ++i)
        {
            if (qPos[i] == val || abs(qPos[i] - val) == abs(i - col))
                return false;
        }
        return true;
    }

    bool solveUtil(vector<int> &qPos, int col = 0)
    {
        if (col == qPos.size())
        {
            solutions.emplace_back(getBoard(qPos));
            return true;
        }

        for (int i = 0; i < qPos.size(); ++i)
        {
            if (isValid(qPos, i, col))
            {
                qPos[col] = i;
                solveUtil(qPos, col + 1);
                qPos[col] = 0;
            }
        }

        return false;
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<int> qPos(n, 0);
        solveUtil(qPos);

        return solutions;
    }
};