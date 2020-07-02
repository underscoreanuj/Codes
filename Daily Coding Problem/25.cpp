/**
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Facebook.
 * Implement regular expression matching with the following special characters:

    . (period) which matches any single character
    * (asterisk) which matches zero or more of the preceding element
 
 * That is, implement a function that takes in a string and a valid regular expression and returns whether or not the string matches the regular expression.
 * For example, given the regular expression "ra." and the string "ray", your function should return true. The same regular expression on the string "raymond" should return false.
 * Given the regular expression ".*at" and the string "chat", your function should return true. The same regular expression on the string "chats" should return false.
 * 
 * 
 * Online Judge: https://leetcode.com/problems/regular-expression-matching/
 * 
*/

// dp solution

class Solution
{
public:
   bool isMatch(string s, string p)
   {
      int s_len = s.length(), p_len = p.length();

      vector<vector<bool>> tab(s_len + 1, vector<bool>(p_len + 1, false));
      tab[0][0] = true;
      for (int i = 2; i <= p_len; ++i)
      {
         if (p[i - 1] == '*')
            tab[0][i] = tab[0][i - 2];
      }

      for (int i = 1; i <= s_len; ++i)
      {
         for (int j = 1; j <= p_len; ++j)
         {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
               tab[i][j] = tab[i - 1][j - 1];
            if (p[j - 1] == '*')
            {
               tab[i][j] = tab[i][j - 2];
               if (s[i - 1] == p[j - 2] || p[j - 2] == '.')
                  tab[i][j] = tab[i][j] | tab[i - 1][j];
            }
         }
      }

      return tab[s_len][p_len];
   }
};

// recursive solution

class Solution
{
public:
   bool isMatch(string &s, string &p, int i = 0, int j = 0)
   {
      if (j >= p.length())
         return i == s.length();

      bool match = (i != s.length() && (s[i] == p[j] || p[j] == '.'));

      if (p.length() - j >= 2 && p[j + 1] == '*')
      {
         return (isMatch(s, p, i, j + 2) || (match && isMatch(s, p, i + 1, j)));
      }
      else
      {
         return match && isMatch(s, p, i + 1, j + 1);
      }
   }
};

auto speedup = []() {
   std::ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   return nullptr;
}();