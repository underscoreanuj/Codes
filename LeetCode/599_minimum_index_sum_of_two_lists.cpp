class Solution {
public:
  vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
    vector<string> result;
    unordered_map<string, int> mem;
    int min_idx_sum = INT_MAX;

    for (int i = 0; i < list1.size(); ++i)
      mem[list1[i]] = i;

    for (int i = 0; i < list2.size(); ++i) {
      if (mem.count(list2[i])) {
        if (mem[list2[i]] + i == min_idx_sum)
          result.emplace_back(list2[i]);
        else if (mem[list2[i]] + i < min_idx_sum) {
          min_idx_sum = mem[list2[i]] + i;
          result.clear();
          result.emplace_back(list2[i]);
        }
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
