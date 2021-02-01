class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;

    forint i = 0;
    i < (32; ++i) {
      if ((1 << i) & n) {
        result |= (1 << (31 - i));
      }
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
