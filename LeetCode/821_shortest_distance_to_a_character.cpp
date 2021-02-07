class Solution {
public:
  vector<int> shortestToChar(string s, char c) {
    int n = s.length(), idx = -1e5;
    vector<int> result(n, -1);

    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == c)
        idx = i;
      result[i] = i - idx;
    }

    idx = 1e5;

    for (int i = s.length() - 1; i >= 0; --i) {
      if (s[i] == c)
        idx = i;
      result[i] = min(result[i], idx - i);
    }

    return result;
  }
};

auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
