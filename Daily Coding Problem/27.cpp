/**
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Facebook.
 * Given a string of round, curly, and square open and closing brackets, return whether the brackets are balanced (well-formed).
 * For example, given the string "([])[]({})", you should return true.
 * Given the string "([)]" or "((()", you should return false.
 * 
 * 
 * Online Judge: https://leetcode.com/problems/valid-parentheses/submissions/
 * 
*/

class Solution
{
public:
    bool isValid(string s)
    {
        if (s.length() & 1)
            return false;

        stack<char> S;
        unordered_map<char, char> map = {{'(', ')'}, {'[', ']'}, {'{', '}'}};

        for (char &c : s)
        {
            if (map.count(c))
                S.push(c);
            else
            {
                if (S.empty() || map[S.top()] != c)
                    return false;
                S.pop();
            }
        }

        return S.size() == 0;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();