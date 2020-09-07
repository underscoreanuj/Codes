// constant space solution

class Solution
{
public:
    int largestOverlapUtil(int x_shift, int y_shift, vector<vector<int>> &A, vector<vector<int>> &B)
    {
        int row = 0, col = 0, n = A.size(), count = 0;

        for (int shift_row = x_shift; shift_row < n; ++shift_row)
        {
            col = 0;
            for (int shift_col = y_shift; shift_col < n; ++shift_col)
            {
                if (A[shift_row][shift_col] == 1 && A[shift_row][shift_col] == B[row][col])
                    ++count;
                ++col;
            }
            ++row;
        }

        return count;
    }

    int largestOverlap(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        int result = INT_MIN, n = A.size();

        for (int x_shift = 0; x_shift < n; ++x_shift)
        {
            for (int y_shift = 0; y_shift < n; ++y_shift)
            {
                result = max(result, largestOverlapUtil(x_shift, y_shift, A, B));
                result = max(result, largestOverlapUtil(x_shift, y_shift, B, A));
            }
        }

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// efficient for sparse matrices

class Solution
{
public:
    int largestOverlap(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        int n = A.size(), result = 0;
        vector<int> t_a, t_b;
        unordered_map<int, int> mem;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (A[i][j] == 1)
                    t_a.emplace_back(i * 100 + j);
                if (B[i][j] == 1)
                    t_b.emplace_back(i * 100 + j);
            }
        }

        for (int &e : t_a)
        {
            for (int &f : t_b)
            {
                ++mem[e - f];
            }
        }

        for (auto element : mem)
            result = max(result, element.second);

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();