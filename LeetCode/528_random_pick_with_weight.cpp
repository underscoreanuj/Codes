class Solution
{
    vector<int> w;

public:
    Solution(vector<int> &w)
    {
        this->w = w;
        for (int i = 1; i < w.size(); ++i)
            this->w[i] += this->w[i - 1];
    }

    int pickIndex()
    {
        return lower_bound(w.begin(), w.end(), (rand() % w[w.size() - 1]) + 1) - w.begin();
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */