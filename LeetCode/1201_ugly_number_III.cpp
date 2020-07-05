class Solution
{
public:
#define ll long long int
    int nthUglyNumber(int n, ll a, ll b, ll c)
    {
        ll l = 1, r = 2 * 10e8, mid = 0, res = 0;
        ll ab = (a * b) / __gcd(a, b);
        ll ac = (a * c) / __gcd(a, c);
        ll bc = (b * c) / __gcd(b, c);
        ll abc = (a * bc) / __gcd(a, bc);

        while (l < r)
        {
            mid = l + ((r - l) >> 1);

            // count(a or b or c) = count(a) + count(b) + count(c) - count(a and b) - count(a and c) - count(b and c) + - count(a and b and c)
            res = (mid / a + mid / b + mid / c - mid / ab - mid / ac - mid / bc + mid / abc);

            if (res == n)
                r = mid;
            else if (res < n)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return r;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();