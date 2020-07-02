class Solution
{
public:
    int ct;

    bool isValid(vector<int> &qPos, int val, int col)
    {
        for (int i = 0; i < col; ++i)
            if (qPos[i] == val || abs(i - col) == abs(qPos[i] - val))
                return false;

        return true;
    }

    void nQueensUtil(vector<int> &qPos, int col = 0)
    {
        if (col == qPos.size())
        {
            ++ct;
            return;
        }

        for (int i = 0; i < qPos.size(); ++i)
        {
            if (isValid(qPos, i, col))
            {
                qPos[col] = i;
                nQueensUtil(qPos, col + 1);
                qPos[col] = 0;
            }
        }
    }

    int totalNQueens(int n)
    {
        if (n <= 1)
            return 1;
        if (n < 4)
            return 0;

        ct = 0;
        vector<int> qPos(n, 0);
        nQueensUtil(qPos);

        return ct;
    }
};