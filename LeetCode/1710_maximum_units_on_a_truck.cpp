class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] > b[1];
        });

        int used = 0, result = 0;

        for (int i = 0; i < boxTypes.size() && truckSize > 0; ++i)
        {
            used = min(truckSize, boxTypes[i][0]);
            truckSize -= used;
            result += boxTypes[i][1] * used;
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