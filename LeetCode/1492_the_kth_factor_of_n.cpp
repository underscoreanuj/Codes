// O(sqrt(n)) solution

class Solution
{
public:
    int kthFactor(int n, int k)
    {
        int res = 1;
        for (; res * res <= n; ++res)
        {
            if (n % res == 0 && --k == 0)
                return res;
        }
        while (res > 1)
        {
            --res;
            if (res * res == n)
                continue;
            if (n % res == 0 && --k == 0)
                return n / res;
        }
        return -1;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// O(n) solution

class Solution
{
public:
    int kthFactor(int n, int k)
    {
        int res = 0;
        while (res <= n && k)
        {
            ++res;
            if (n % res == 0)
                --k;
        }

        return res <= n ? res : -1;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();