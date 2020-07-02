/**
 * 
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Palantir.
 * Write an algorithm to justify text. Given a sequence of words and an integer line length k, return a list of strings which represents each line, fully justified.
 * More specifically, you should have as many words as possible in each line. There should be at least one space between each word. Pad extra spaces when necessary so that each line has exactly length k. Spaces should be distributed as equally as possible, with the extra spaces, if any, distributed starting from the left.
 * If you can only fit one word on a line, then you should pad the right-hand side with spaces.
 * Each word is guaranteed not to be longer than k.
 * For example, given the list of words ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"] and k = 16, you should return the following:

        ["the  quick brown", # 1 extra space on the left
        "fox  jumps  over", # 2 extra spaces distributed evenly
        "the   lazy   dog"] # 4 extra spaces distributed evenly
 *
 * 
 * 
 * Online Judge: https://leetcode.com/problems/text-justification/
 * 
 */

class Solution
{
public:
    string getJustifiedLine(vector<string> &words, int maxWidth, int start, int end, int len, int space_count, bool is_last)
    {
        string res = "";

        int spaces = maxWidth - len;
        spaces += space_count;

        int same_spaces = (is_last || space_count == 0) ? 0 : spaces / space_count;
        int extra_spaces = (is_last || space_count == 0) ? space_count : spaces % space_count;
        int trail_spaces = (is_last || space_count == 0) ? maxWidth - len : 0;

        for (int i = start; i <= end; ++i)
        {
            res.append(words[i]);

            if (i < end)
            {
                res.append(same_spaces, ' ');
                if (extra_spaces)
                {
                    res.append(1, ' ');
                    --extra_spaces;
                }
            }
        }
        if (trail_spaces)
            res.append(trail_spaces, ' ');

        return res;
    }

    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> result;
        int len = -1, space_count = -1, start = 0;

        for (int i = 0; i < words.size(); ++i)
        {
            if (len + words[i].length() + 1 <= maxWidth)
            {
                len += words[i].length() + 1;
                ++space_count;
            }
            else
            {
                result.emplace_back(getJustifiedLine(words, maxWidth, start, i - 1, len, space_count, false));
                start = i;
                len = -1;
                space_count = -1;
                --i;
            }
        }

        result.emplace_back(getJustifiedLine(words, maxWidth, start, words.size() - 1, len, space_count, true));

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();