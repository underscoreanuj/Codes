class Solution
{
public:
    string removeOuterParentheses(string S)
    {
        string result;
        int depth = 0;

        for (int i = 0; i < S.length() - 1; ++i)
        {
            if (S[i] == '(')
            {
                if (depth > 0)
                    result += "(";
                ++depth;
            }
            else
            {
                --depth;
                if (depth > 0)
                    result += ")";
            }
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