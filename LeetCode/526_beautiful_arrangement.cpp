// permutation based solution

class Solution
{
public:
    void permute(vector<int> &perm, int &result, int idx = 0)
    {
        if (idx == perm.size())
            ++result;
        else
        {
            for (int i = idx; i < perm.size(); ++i)
            {
                if (perm[i] % (idx + 1) == 0 || (idx + 1) % perm[i] == 0)
                {
                    swap(perm[i], perm[idx]);
                    permute(perm, result, idx + 1);
                    swap(perm[i], perm[idx]);
                }
            }
        }
    }

    int countArrangement(int n)
    {
        int result = 0;
        vector<int> perm(n, 0);
        for (int i = 0; i < n; ++i)
            perm[i] = i + 1;

        permute(perm, result);

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();