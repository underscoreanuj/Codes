class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        long first_max = LONG_MIN, second_max = LONG_MIN, third_max = LONG_MIN;

        for (int &n : nums)
        {
            if (n == first_max || n == second_max || n == third_max)
                continue;
            if (n > first_max)
            {
                third_max = second_max;
                second_max = first_max;
                first_max = n;
            }
            else if (n > second_max)
            {
                third_max = second_max;
                second_max = n;
            }
            else if (n > third_max)
                third_max = n;
        }

        if (third_max == LONG_MIN)
            return first_max;

        return third_max;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();