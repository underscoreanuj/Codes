// normal solution

class Solution
{
public:
    void trim(string &s)
    {
        int i = 0;
        while (i < s.length() && s[i] == ' ')
            ++i;
        s = s.substr(i);

        i = s.length() - 1;

        while (i >= 0 && s[i] == ' ')
            --i;
        s = s.substr(0, i + 1);
    }

    bool isNumber(string s)
    {
        trim(s);

        bool num_found = false, decimal_found = false, exponent_found = false;

        for (int i = 0; i < s.length(); ++i)
        {
            switch (s[i])
            {
            case 'e':
                if (exponent_found || !num_found)
                    return false;
                exponent_found = true;
                num_found = false;
                break;
            case '.':
                if (decimal_found || exponent_found)
                    return false;
                decimal_found = true;
                break;
            case '+':
            case '-':
                if (i != 0 && s[i - 1] != 'e')
                    return false;
                break;
            default:
                if (!isdigit(s[i]))
                    return false;
                num_found = true;
                break;
            }
        }

        return num_found;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();