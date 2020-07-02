class Solution
{
public:
    string getLine(vector<string> &words, int maxWidth, int l, int r, int len, int space_ct, bool last)
    {
        int spaces = maxWidth - len;
        spaces += space_ct;

        int same = (last || (space_ct == 0)) ? 0 : spaces / space_ct;
        int extra = (last || (space_ct == 0)) ? space_ct : spaces % space_ct;
        int trail = (last || (space_ct == 0)) ? maxWidth - len : 0;

        string res;

        for (int i = l; i <= r; ++i)
        {
            res += words[i];

            if (i < r)
            {
                res.append(same, ' ');
                if (extra)
                {
                    res.append(1, ' ');
                    --extra;
                }
            }
        }

        if (trail)
            res.append(trail, ' ');

        return res;
    }

    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> result;
        int l = 0, len = -1, space_ct = -1;

        for (int i = 0; i < words.size(); ++i)
        {
            if (len + words[i].length() + 1 <= maxWidth)
            {
                len += words[i].length() + 1;
                ++space_ct;
            }
            else
            {
                result.emplace_back(getLine(words, maxWidth, l, i - 1, len, space_ct, false));
                l = i;
                --i;
                len = -1;
                space_ct = -1;
            }
        }
        result.emplace_back(getLine(words, maxWidth, l, words.size() - 1, len, space_ct, true));

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();