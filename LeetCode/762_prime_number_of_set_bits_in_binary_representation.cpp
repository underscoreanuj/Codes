class Solution {
public:
  int countPrimeSetBits(int L, int R) {
    unordered_set<int> mem = {2,  3,  5, 7, 11,
                              13, 17, 19}; // since 1e6 can go as high as 2^20
    int result = 0;

    for (int i = L; i <= R; ++i)
      result += mem.count(__builtin_popcount(i));

    return result;
  }
};

auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
