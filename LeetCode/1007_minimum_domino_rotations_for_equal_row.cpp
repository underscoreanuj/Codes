class Solution
{
public:
    int getMinRotations(vector<int> &A, vector<int> &B, int x)
    {
        int aRot = 0, bRot = 0;
        for (int i = 0; i < A.size(); ++i)
        {
            if (A[i] != x && B[i] != x)
                return -1;
            if (A[i] == x && B[i] != x)
                ++bRot;
            if (A[i] != x && B[i] == x)
                ++aRot;
        }

        return min(aRot, bRot);
    }

    int minDominoRotations(vector<int> &A, vector<int> &B)
    {
        int a = getMinRotations(A, B, A[0]);
        int b = getMinRotations(A, B, B[0]);

        if (a == -1)
            return b;
        else if (b == -1)
            return a;

        return min(a, b);
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();