// better solution

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int result = 0;

        for (int &n : nums)
        {
            result += ((n >= 10 && n <= 99) || (n >= 1000 && n <= 9999) || (n == 100000)) ? 1 : 0;
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

// simple solution

class Solution
{
public:
    int getDigitCount(int n)
    {
        int count = 0;
        while (n)
        {
            n /= 10;
            ++count;
        }

        return count;
    }

    int findNumbers(vector<int> &nums)
    {
        int result = 0;

        for (int &n : nums)
            result += (getDigitCount(n) % 2 ? 0 : 1);

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();