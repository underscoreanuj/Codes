class Solution {
public:
  void letterCasePermutationUtil(string &s, vector<string> &result,
                                 int idx = 0) {
    if (idx == s.length()) {
      result.emplace_back(s);
      return;
    }

    letterCasePermutationUtil(s, result, idx + 1);
    if (isalpha(s[idx])) {
      s[idx] ^= 32;
      letterCasePermutationUtil(s, result, idx + 1);
    }
  }
  vector<string> letterCasePermutation(string S) {
    vector<string> result;
    letterCasePermutationUtil(S, result);

    return result;
  }
};

auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
