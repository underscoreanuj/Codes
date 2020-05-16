// time: O(n), space: O(1) solution

class Solution
{
public:
    int kadane(vector<int> &A, int start, int end)
    {
        if (start >= end)
            return 0;

        int ans = A[start], sum = 0;
        for (int i = start; i < end; ++i)
        {
            sum = A[i] + max(sum, 0);
            ans = max(ans, sum);
        }

        return ans;
    }
    int maxSubarraySumCircular(vector<int> &A)
    {
        int ans = kadane(A, 0, A.size());
        int sum = accumulate(A.begin(), A.end(), 0);
        transform(A.begin(), A.end(), A.begin(), bind(multiplies<int>(), placeholders::_1, -1));

        return max(ans, sum + max(kadane(A, 0, A.size() - 1), kadane(A, 1, A.size())));
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// time: O(n), space: O(n) solution

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &A)
    {
        int n = A.size(), ans = INT_MIN, sum = 0;

        for (int i = 0; i < n; ++i)
        {
            sum = A[i] + max(sum, 0);
            ans = max(ans, sum);
        }

        vector<int> rSum(n, 0);
        rSum[n - 1] = A[n - 1];

        for (int i = n - 2; i >= 0; --i)
            rSum[i] = rSum[i + 1] + A[i];
        for (int i = n - 2; i >= 0; --i)
            rSum[i] = max(rSum[i], rSum[i + 1]);

        sum = 0;
        for (int i = 0; i < n - 2; ++i)
        {
            sum += A[i];
            ans = max(ans, sum + rSum[i + 2]);
        }

        return ans;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// time: O(n), space: O(n) solution

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &A)
    {
        int n = A.size(), ans = INT_MIN;
        vector<int> B(2 * n + 1, 0);
        deque<int> Q;
        Q.push_back(0);

        for (int i = 0; i < 2 * n; ++i)
            B[i + 1] = B[i] + A[i % n];

        for (int i = 1; i < 2 * n; ++i)
        {
            while (Q.front() < i - n)
                Q.pop_front();

            ans = max(ans, B[i] - B[Q.front()]);

            while (!Q.empty() && B[i] <= B[Q.back()])
                Q.pop_back();

            Q.push_back(i);
        }

        return ans;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();