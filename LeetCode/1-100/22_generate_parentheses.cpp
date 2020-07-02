class Solution
{
public:
    vector<string> ret;

    void generateParenthesis(string cb, int o, int c)
    {
        if (o == 0 && c == 0)
        {
            ret.push_back(cb);
            return;
        }

        if (o > 0)
            generateParenthesis(cb + "(", o - 1, c + 1);
        if (c > 0)
            generateParenthesis(cb + ")", o, c - 1);
    }

    vector<string> generateParenthesis(int n)
    {
        if (n < 1)
            return {};
        generateParenthesis("", n, 0);

        return ret;
    }
};