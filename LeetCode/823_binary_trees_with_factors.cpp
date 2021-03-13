class Solution {
public:
  int numFactoredBinaryTrees(vector<int> &arr) {
    long result = 0, div = 0, MOD = 1e9 + 7;
    unordered_map<int, long> mem;

    sort(arr.begin(), arr.end());
    for (int &a : arr)
      mem[a] = 1;

    for (int i = 0; i < arr.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (arr[i] % arr[j] == 0) {
          div = arr[i] / arr[j];
          if (mem.count(div))
            mem[arr[i]] = (mem[arr[i]] + mem[arr[j]] * mem[div]) % MOD;
        }
      }
    }

    for (auto &m : mem) {
      result += m.second;
      if (result >= MOD)
        result -= MOD;
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
