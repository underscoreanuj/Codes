// O(n + m) solution

class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        vector<vector<int>> result;

        int i = 0, j = 0;

        while (i < A.size() && j < B.size())
        {
            if (B[j][0] > A[i][1])
                ++i;
            else if (A[i][0] > B[j][1])
                ++j;
            else
            {
                result.push_back({max(A[i][0], B[j][0]), min(A[i][1], B[j][1])});
                if (A[i][1] < B[j][1])
                    ++i;
                else
                    ++j;
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

// O(n*m) solution

class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        vector<vector<int>> result;

        for (auto &a : A)
        {
            for (auto &b : B)
            {
                if (b[0] > a[1])
                    break;

                if ((b[0] >= a[0] && b[0] <= a[1]) || (b[1] >= a[0] && b[1] <= a[1]))
                {
                    result.push_back({max(a[0], b[0]), min(a[1], b[1])});
                }
                else if ((a[0] >= b[0] && a[0] <= b[1]) || (a[1] >= b[0] && a[1] <= b[1]))
                {
                    result.push_back({max(a[0], b[0]), min(a[1], b[1])});
                }
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