class Solution
{
public:
    bool buddyStrings(string A, string B)
    {
        if (A.length() != B.length())
            return false;

        if (A == B && unordered_set<char>(A.begin(), A.end()).size() < A.size())
            return true;

        vector<int> diff;
        for (int i = 0; i < A.size(); ++i)
            if (A[i] != B[i])
                diff.emplace_back(i);

        return diff.size() == 2 && A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]];
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();