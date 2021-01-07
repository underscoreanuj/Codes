class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int maximum_candies = *max_element(candies.begin(), candies.end());
        vector<bool> result;

        for (int &candy : candies)
            result.emplace_back(candy + extraCandies >= maximum_candies);

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();