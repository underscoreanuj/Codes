class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        if (digits.size() == 0)
            return {1};
        if (digits.size() == 1)
        {
            if (digits[0] == 9)
                return {1, 0};
            else
                return {digits[0] + 1};
        }

        int n = digits.size();

        vector<int> ret;
        digits[n - 1] += 1;

        for (int i = n - 1; i >= 0; --i)
        {
            if (digits[i] == 10)
            {
                digits[i] = 0;
                if (i - 1 >= 0)
                    digits[i - 1] += 1;
                else
                    ret.emplace_back(1);
            }
            else
                break;
        }
        for (int i : digits)
            ret.emplace_back(i);

        return ret;
    }
};