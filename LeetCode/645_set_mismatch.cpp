class Solution {
public:
  vector<int> findErrorNums(vector<int> &nums) {
    int n = nums.size(), nums_xor = 0, pos = 0, duplicate = 0, missing = 0;
    for (int &num : nums)
      nums_xor ^= num;
    for (int i = 1; i <= n; ++i)
      nums_xor ^= i;

    pos = nums_xor & ~(nums_xor - 1);

    for (int &num : nums) {
      if (num & pos)
        duplicate ^= num;
      else
        missing ^= num;
    }

    for (int i = 1; i <= n; ++i) {
      if (i & pos)
        duplicate ^= i;
      else
        missing ^= i;
    }

    for (int &num : nums) {
      if (missing == num) {
        return {missing, duplicate};
      }
    }

    return {duplicate, missing};
  }
};

auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
