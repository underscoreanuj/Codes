// O(n) solution

class Solution {
public:
  int findLHS(vector<int> &nums) {
    int result = 0;
    unordered_set<int> mem;
    unordered_map<int, int> freq;

    for (int &n : nums) {
      ++freq[n];
      mem.insert(n);
    }

    for (int e : mem) {
      if (freq.count(e - 1)) {
        result = max(result, freq[e] + freq[e - 1]);
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

// O(nlogn) solution with constant space

class Solution {
public:
  int findLHS(vector<int> &nums) {
    int result = 0, prev_count = 1, count = 0;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i) {
      count = 1;
      if (i > 0 && nums[i] - nums[i - 1] == 1) {
        while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
          ++i;
          ++count;
        }
        result = max(result, count + prev_count);
      } else {
        while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
          ++i;
          ++count;
        }
      }
      prev_count = count;
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
