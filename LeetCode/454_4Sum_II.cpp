class Solution
{
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        int result = 0;
        unordered_map<int, int> mem;

        for (int &a : A)
            for (int &b : B)
                ++mem[a + b];

        for (int &c : C)
            for (int &d : D)
                result += mem[-(c + d)];

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();