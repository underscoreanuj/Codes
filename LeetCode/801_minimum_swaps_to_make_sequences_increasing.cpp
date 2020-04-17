class Solution
{
public:
    int minSwap(vector<int> &A, vector<int> &B)
    {
        int w1 = 0, w2 = 0, s1 = 1, s2 = 0;

        for (int i = 1; i < A.size(); ++i)
        {
            w2 = s2 = 2001;
            if (A[i] > A[i - 1] && B[i] > B[i - 1])
            {
                w2 = w1;
                s2 = 1 + s1;
            }
            if (A[i] > B[i - 1] && B[i] > A[i - 1])
            {
                w2 = min(w2, s1);
                s2 = min(s2, 1 + w1);
            }
            w1 = w2;
            s1 = s2;
        }

        return min(w1, s1);
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();