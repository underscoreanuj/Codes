/**
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Microsoft.
 * You have an N by N board. Write a function that, given N, returns the number of possible arrangements of the board where N queens can be placed on the board without threatening each other, i.e. no two queens share the same row, column, or diagonal.
 * 
 * 
 * Online Judge: https://leetcode.com/problems/n-queens-ii/
 * 
 */

class Solution
{
public:
    int count;

    bool isValid(vector<int> &board, int val, int limit)
    {
        for (int i = 0; i < limit; ++i)
        {
            if (board[i] == val || abs(val - board[i]) == abs(limit - i))
                return false;
        }
        return true;
    }

    void totalNQueenUtil(vector<int> &board, int idx = 0)
    {
        if (idx == board.size())
        {
            ++count;
            return;
        }
        for (int i = 0; i < board.size(); ++i)
        {
            if (isValid(board, i, idx))
            {
                board[idx] = i;
                totalNQueenUtil(board, idx + 1);
            }
        }
    }

    int totalNQueens(int n)
    {
        count = 0;
        vector<int> board(n, -1);

        totalNQueenUtil(board);

        return count;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();