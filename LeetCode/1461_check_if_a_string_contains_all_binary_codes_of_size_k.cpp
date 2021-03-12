class Solution {
public:
  bool hasAllCodes(string s, int k) {
    if (s.length() < k)
      return false;

    unordered_set<int> mem;
    int num = 0;

    for (int i = 0; i < s.length(); ++i) {
      num <<= 1;
      num |= (s[i] - '0');
      if (i >= k - 1) {
        mem.insert(num);
        num &= ~(1 << (k - 1));
      }
    }

    return mem.size() >= (1 << k);
  }
  P
};

auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
