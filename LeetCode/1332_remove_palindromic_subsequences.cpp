class Solution {
public:
  int removePalindromeSub(string s) {
    if (!s.length())
      return 0;

    int len = s.length();
    bool flag = false;
    for (int i = 0; i < len >> 1; ++i) {
      if (s[i] != s[len - i - 1]) {
        flag = true;
        break;
      }
    }

    return flag ? 2 : 1;
  }
};
