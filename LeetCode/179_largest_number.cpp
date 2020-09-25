class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> numbers;
        for (int &n : nums)
            numbers.emplace_back(to_string(n));

        sort(numbers.begin(), numbers.end(), [](const string &a, const string &b) {
            return a + b > b + a;
        });

        string result = "";
        for (auto n : numbers)
            result += n;

        return result[0] == '0' ? "0" : result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();