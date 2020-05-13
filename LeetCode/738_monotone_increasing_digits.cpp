class Solution
{
public:
    int monotoneIncreasingDigits(int N)
    {
        string num = to_string(N);

        int start = num.length();
        for (int i = num.length() - 1; i > 0; --i)
        {
            if (num[i - 1] > num[i])
            {
                start = i;
                --num[i - 1];
            }
        }
        for (int i = start; i < num.length(); ++i)
            num[i] = '9';

        return stoi(num);
    }
};