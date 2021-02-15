class Solution {
public:
  int findOneCount(vector<int> &v) {
    int l = 0, r = v.size() - 1, m = 0, res = -1;

    while (l <= r) {
      m = l + ((r - l) >> 1);

      if (v[m] == 1) {
        res = m;
        l = m + 1;
      } else
        r = m - 1;
    }

    return res == -1 ? 0 : res + 1;
  }

  vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
    vector<int> result;
    priority_queue<pair<int, int>> pq;
    int sum = 0;

    for (int i = 0; i < mat.size(); ++i) {
      sum = findOneCount(mat[i]);

      if (pq.size() < k)
        pq.push({sum, i});
      else if (sum < pq.top().first) {
        pq.pop();
        pq.push({sum, i});
      }
    }

    while (pq.size()) {
      result.emplace_back(pq.top().second);
      pq.pop();
    }

    reverse(result.begin(), result.end());

    return result;
  }
};

auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
