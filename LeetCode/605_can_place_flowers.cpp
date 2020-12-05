class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        bool prev = false, next = false;
        int last_flower_idx = -2, count = 0;

        for (int i = 0; i < flowerbed.size(); ++i)
        {
            if (flowerbed[i] == 1)
                last_flower_idx = i;
            else
            {
                prev = i > 0 ? flowerbed[i - 1] == 0 : true;
                next = i < flowerbed.size() - 1 ? flowerbed[i + 1] == 0 : true;
                if (prev && next && i - last_flower_idx > 1)
                {
                    last_flower_idx = i;
                    ++count;
                }
            }

            if (count >= n)
                return true;
        }

        return false;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    -cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();