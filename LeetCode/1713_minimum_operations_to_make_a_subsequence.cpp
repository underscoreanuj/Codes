// the target array has all distinct elements, so we map them to an increasing sequence,
// and find the LIS on the arr only for those mapped elements and return the difference between the target size and the LIS

class Solution
{
public:
    int minOperations(vector<int> &target, vector<int> &arr)
    {
        int c = 0, idx = 0;
        unordered_map<int, int> transformed;
        vector<int> tab;

        for (int i = 0; i < target.size(); ++i)
            transformed[target[i]] = i;

        for (int &a : arr)
        {
            if (transformed.count(a))
            {
                c = transformed[a];
                if (tab.empty() || c > tab.back())
                    tab.emplace_back(c);
                else
                {
                    idx = lower_bound(tab.begin(), tab.end(), c) - tab.begin();
                    tab[idx] = c;
                }
            }
        }

        return target.size() - tab.size();
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();