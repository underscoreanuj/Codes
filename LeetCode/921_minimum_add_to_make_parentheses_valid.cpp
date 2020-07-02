class Solution
{
public:
    int minAddToMakeValid(string S)
    {
        int result = 0, count = 0;
        for (char &c : S)
        {
            if (c == '(')
                ++count;
            else
            {
                if (count == 0)
                    ++result;
                else
                    --count;
            }
        }

        return result + count;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();