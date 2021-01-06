class Solution
{
public:
    int maxDepth(string s)
    {
        int result = 0, depth = 0;

        for (char &c : s)
        {
            depth += (c == '(') ? 1 : ((c == ')') ? -1 : 0);
            result = max(result, depth);
        }

        return result;
    }
};