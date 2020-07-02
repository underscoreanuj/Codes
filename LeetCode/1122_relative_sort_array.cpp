class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int> HashMap(1001, 0);
        int idx = 0;

        for (int &a : arr1)
            ++HashMap[a];

        for (int &b : arr2)
        {
            while (HashMap[b] > 0)
            {
                arr1[idx++] = b;
                --HashMap[b];
            }
        }

        for (int i = 0; i < 1001; ++i)
        {
            while (HashMap[i] > 0)
            {
                arr1[idx++] = i;
                --HashMap[i];
            }
        }

        return arr1;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();