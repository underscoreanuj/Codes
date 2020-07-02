class Solution
{
public:
    int scoreOfParentheses(string S)
    {
        int score = 0, depth = 0;

        for (int i = 0; i < S.length(); ++i)
        {
            if (S[i] == '(')
                ++depth;
            else
            {
                --depth;
                if (S[i - 1] == '(')
                    score += 1 << depth;
            }
        }

        return score;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();