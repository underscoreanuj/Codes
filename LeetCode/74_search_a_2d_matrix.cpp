// class Solution
// {
// public:
//     bool searchMatrix(vector<vector<int>> &matrix, int target)
//     {
//         if (matrix.size() == 0)
//             return false;
//         if (matrix[0].size() == 0)
//             return false;
//         if (target < matrix[0][0])
//             return false;
//         if (target > matrix[matrix.size() - 1][matrix[0].size() - 1])
//             return false;

//         int m = matrix.size();
//         int n = matrix[0].size();
//         int l = 0, r = m * n - 1, mid = 0, val = 0;

//         while (l <= r)
//         {
//             mid = l + ((r - l) >> 1);
//             val = matrix[mid / n][mid % n];
//             if (val == target)
//                 return true;
//             else if (val < target)
//                 l = mid + 1;
//             else
//                 r = mid - 1;
//         }

//         return false;
//     }
// };

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