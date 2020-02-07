class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() == 0)
            return false;
        if (matrix[0].size() == 0)
            return false;
        if (target < matrix[0][0])
            return false;
        if (target > matrix[matrix.size() - 1][matrix[0].size() - 1])
            return false;

        int row = lower_bound(matrix.begin(), matrix.end(), target, [](const vector<int> &o, const int &t) {
                      return o[o.size() - 1] < t;
                  }) -
                  matrix.begin();

        return binary_search(matrix[row].begin(), matrix[row].end(), target);
    }
};