// best solution

class Solution
{
public:
    string frequencySort(string s)
    {
        vector<int> freq(128, 0);
        map<int, string, greater<int>> bucket;
        int count = 0;
        char c;
        string res = "";

        for (char &c : s)
            ++freq[c];

        for (int i = 0; i < freq.size(); ++i)
        {
            if (freq[i])
            {
                c = i;
                count = freq[i];

                bucket[count].append(count, c);
            }
        }

        for (auto b : bucket)
            res += b.second;

        return res;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// bucket sort O(n)

class Solution
{
public:
    string frequencySort(string s)
    {
        vector<int> freq(128, 0);
        vector<string> bucket(s.length() + 1, "");
        int count = 0;
        char c;
        string res = "";

        for (char &c : s)
            ++freq[c];

        for (int i = 0; i < freq.size(); ++i)
        {
            if (freq[i])
            {
                c = i;
                count = freq[i];

                bucket[count].append(count, c);
            }
        }

        for (int i = bucket.size() - 1; i >= 0; --i)
        {
            if (bucket[i].length())
                res += bucket[i];
        }

        return res;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// sorting with custom comparator O(nlogn)

class Solution
{
public:
    string frequencySort(string s)
    {
        int freq[128];
        memset(freq, 0, sizeof(freq));

        for (char &c : s)
            ++freq[c];

        sort(s.begin(), s.end(), [&freq](const char &c1, const char &c2) {
            if (freq[c1] > freq[c2] || (freq[c1] == freq[c2] && c1 > c2))
                return true;
            return false;
        });

        return s;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();