// better solution with modulo 14

class Solution
{
public:
    vector<int> prisonAfterNDays(vector<int> &cells, int N)
    {
        vector<int> res(8, 0);
        N = (N % 14 == 0) ? 14 : N % 14;

        while (N--)
        {
            for (int i = 1; i < 7; ++i)
                res[i] = cells[i - 1] == cells[i + 1] ? 1 : 0;
            cells = res;
        }
        return cells;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// simple solution with memoization

class Solution
{
public:
    int getHash(vector<int> &cells)
    {
        int hash = 0;
        for (int i = 0; i < 8; ++i)
        {
            hash += cells[i] ? 1 << (7 - i) : 0;
        }
        return hash;
    }

    vector<int> prisonAfterNDays(vector<int> &cells, int N)
    {
        vector<int> res;
        vector<int> mem(256, -1);
        int seen = 0;

        while (N)
        {
            res = vector<int>(8, 0);
            mem[getHash(cells)] = N--;
            for (int i = 1; i < 7; ++i)
                res[i] = cells[i - 1] == cells[i + 1] ? 1 : 0;
            seen = mem[getHash(res)];
            if (seen != -1)
                N %= (seen - N);
            cells = res;
        }
        return cells;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();