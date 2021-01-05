// cyclic sort solution

class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {
        for (int i = 0; i < indices.size(); ++i)
        {
            while (i != indices[i])
            {
                swap(s[i], s[indices[i]]);
                swap(indices[i], indices[indices[i]]);
            }
        }

        return s;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// simple approach

class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {
        string res = s;
        for (int i = 0; i < indices.size(); ++i)
            res[indices[i]] = s[i];

        return res;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();