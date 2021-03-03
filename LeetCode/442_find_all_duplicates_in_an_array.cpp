class Solution {
public:
  vector<int> findDuplicates(vector<int> &nums) {
    vector<int> result;
    int idx = 0;

    for (int &num : nums) {
      idx = abs(num) - 1;
      if (nums[idx] < 0)
        result.emplace_back(idx + 1);
      else
        nums[idx] = -nums[idx];
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
