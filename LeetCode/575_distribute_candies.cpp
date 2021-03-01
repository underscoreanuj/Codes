class Solution {
public:
  int distributeCandies(vector<int> &candyType) {
    return min(unordered_set<int>(candyType.begin(), candyType.end()).size(),
               (candyType.size() >> 1));
  }
};

auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
