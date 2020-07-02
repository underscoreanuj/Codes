// solution without converting to string

class Solution
{
public:
    int maximum69Number(int num)
    {
        int last_six = -1, tmp = num, i = 0;
        while (tmp)
        {
            if (tmp % 10 == 6)
                last_six = i;
            tmp /= 10;
            ++i;
        }

        if (last_six == -1)
            return num;
        num += 3 * pow(10, last_six);
        return num;
    }
};

// normal solution

class Solution
{
public:
    int maximum69Number(int num)
    {
        string n = to_string(num);
        for (int i = 0; i < n.length(); ++i)
            if (n[i] == '6')
            {
                n[i] = '9';
                break;
            }

        return stoi(n);
    }
};