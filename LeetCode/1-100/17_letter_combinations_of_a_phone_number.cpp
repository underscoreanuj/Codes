class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.length() == 0)
            return {};

        vector<string> NUMS = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ret = {""}, tmp;

        for (char d : digits)
        {
            tmp.clear();
            for (string e : ret)
            {
                for (char c : NUMS[d - '0'])
                {
                    tmp.push_back(e + c);
                }
            }
            ret = tmp;
        }

        return ret;
    }
};