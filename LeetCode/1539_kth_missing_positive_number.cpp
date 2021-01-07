// log(n) solution

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int l = 0, r = arr.size() - 1, mid = 0, ans = 0;

        while (l <= r)
        {
            mid = l + ((r - l) >> 1);

            if (arr[mid] - mid - 1 < k)
            {
                ans = mid + 1;
                l = mid + 1;
            }
            else
            {
                ans = mid;
                r = mid - 1;
            }
        }

        return k + ans;
    }
};

// linear solution

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int prev = 0, missing = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            missing = arr[i] - prev - 1;
            if (k <= missing)
            {
                return prev + k;
            }
            k -= missing;
            prev = arr[i];
        }

        return arr.back() + k;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();