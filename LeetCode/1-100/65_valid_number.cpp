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

        bool num_found = false, exponent_found = false, decimal_found = false;

        for (int i = 0; i < s.length(); ++i)
        {
            switch (s[i])
            {
            case '.':
                if (decimal_found || exponent_found)
                    return false;
                decimal_found = true;
                break;
            case 'e':
                if (exponent_found || !num_found)
                    return false;
                exponent_found = true;
                num_found = false;
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

// automaton solution

class Solution
{
public:
    bool isNumber(string s)
    {
        string BLANK = "blank";
        string SIGN = "sign";
        string NUMBER = "number";
        string DECIMAL = "decimal";
        string EXPONENT = "exponent";

        vector<unordered_map<string, int>> automaton = {
            // *** => final state
            {},
            // state 1 : starting state                 | expects : blank, sign, number, decimal
            {{BLANK, 1}, {SIGN, 2}, {NUMBER, 3}, {DECIMAL, 4}},
            // state 2 : sign                           | expects : number, decimal
            {{DECIMAL, 4}, {NUMBER, 3}},
            // ***state 3 : number                      | expects : blank, number, decimal, exponent
            {{BLANK, 9}, {NUMBER, 3}, {DECIMAL, 5}, {EXPONENT, 6}},
            // state 4 : decimal                        | expects : number
            {{NUMBER, 5}},
            // ***state 5 : after decimal               | expects :  blank, number, exponent
            {{BLANK, 9}, {NUMBER, 5}, {EXPONENT, 6}},
            // state 6 : exponent                       | expects : sign, number
            {{SIGN, 7}, {NUMBER, 8}},
            // state 7 : sign after exponent            | expects : number
            {{NUMBER, 8}},
            // ***state 8 : number after exponent/sign  | expects : blank, number
            {{BLANK, 9}, {NUMBER, 8}},
            // ***state 9 : blank                       | expects : blank
            {{BLANK, 9}}};

        int cur_state = 1;
        string state = "";

        for (char &c : s)
        {
            if (c == ' ')
                state = BLANK;
            else if (c == '+' || c == '-')
                state = SIGN;
            else if (c == '.')
                state = DECIMAL;
            else if (c == 'e')
                state = EXPONENT;
            else if (isdigit(c))
                state = NUMBER;
            else
                return false;

            if (automaton[cur_state].count(state))
            {
                cur_state = automaton[cur_state][state];
            }
            else
                return false;
        }

        return (cur_state == 3 || cur_state == 5 || cur_state == 8 || cur_state == 9);
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();