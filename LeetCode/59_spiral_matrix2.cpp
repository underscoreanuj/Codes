class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        if (n == 0)
            return {};
        if (n == 1)
            return {{1}};

        vector<vector<int>> ret(n, vector<int>(n, 0));

        int h_start = 0, h_end = n - 1;
        int v_start = 0, v_end = n - 1;
        int val = 1;

        while (true)
        {
            for (int i = h_start; i <= h_end; ++i)
                ret[v_start][i] = val++;
            ++v_start;
            if (v_start > v_end)
                break;
            for (int i = v_start; i <= v_end; ++i)
                ret[i][h_end] = val++;
            --h_end;
            if (h_start > h_end)
                break;
            for (int i = h_end; i >= h_start; --i)
                ret[v_end][i] = val++;
            --v_end;
            if (v_start > v_end)
                break;
            for (int i = v_end; i >= v_start; --i)
                ret[i][h_start] = val++;
            ++h_start;
            if (h_start > h_end)
                break;
        }

        return ret;
    }
};