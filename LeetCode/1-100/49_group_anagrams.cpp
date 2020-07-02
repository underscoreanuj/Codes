class Solution
{
public:
    vector<int> Counts;

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> M;
        string key;
        Counts = vector<int>(26, 0);

        for (string s : strs)
        {
            key = CountSort(s);
            M[key].push_back(s);
        }

        for (auto m : M)
            ret.push_back(m.second);

        return ret;
    }

    string CountSort(string s)
    {
        fill(Counts.begin(), Counts.end(), 0);
        string s_string;

        for (int i = 0; i < s.length(); ++i)
            ++Counts[s[i] - 'a'];

        for (int i = 0; i < 26; ++i)
        {
            if (Counts[i] > 0)
            {
                s_string += string(Counts[i], i + 'a');
            }
        }

        return s_string;
    }
};