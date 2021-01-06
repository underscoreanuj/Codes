class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        int row1 = 0, col1 = 0, row2 = 0, col2 = 0;

        while (true)
        {
            if (col1 == word1[row1].length())
            {
                ++row1;
                col1 = 0;
            }
            if (col2 == word2[row2].length())
            {
                ++row2;
                col2 = 0;
            }

            if (row1 == word1.size() && row2 == word2.size())
                break;
            if ((row1 == word1.size() && row2 != word2.size()) || (row1 != word1.size() && row2 == word2.size()))
                return false;
            if (word1[row1][col1++] != word2[row2][col2++])
                return false;
        }

        return true;
    }
};