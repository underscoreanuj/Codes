// dp solution

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<int> tab(amount + 1, 0);
        tab[0] = 1;

        for (int &c : coins)
        {
            for (int i = c; i <= amount; ++i)
                tab[i] += tab[i - c];
        }

        return tab[amount];
    }
};