class Solution
{
public:
    string shiftingLetters(string S, vector<int> &shifts)
    {
        int n = shifts.size();
        for (int i = n - 1; i >= 0; --i)
        {
            shifts[i] %= 26;
            shifts[i] += (i + 1 < n) ? shifts[i + 1] : 0;
            S[i] = ((S[i] - 'a' + shifts[i]) % 26) + 'a';
        }

        return S;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();