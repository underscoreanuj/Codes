class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0)
            return {};

        int h_start = 0, h_end = matrix[0].size() - 1;
        int v_start = 0, v_end = matrix.size() - 1;

        vector<int> ret;

        while (true)
        {
            if (h_start > h_end)
                break;
            for (int i = h_start; i <= h_end; ++i)
                ret.emplace_back(matrix[v_start][i]);
            ++v_start;
            if (v_start > v_end)
                break;
            for (int i = v_start; i <= v_end; ++i)
                ret.emplace_back(matrix[i][h_end]);
            --h_end;
            if (h_start > h_end)
                break;
            for (int i = h_end; i >= h_start; --i)
                ret.emplace_back(matrix[v_end][i]);
            --v_end;
            if (v_start > v_end)
                break;
            for (int i = v_end; i >= v_start; --i)
                ret.emplace_back(matrix[i][h_start]);
            ++h_start;
        }

        return ret;
    }
};