class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    int n = grid.size(), r = 0, c = 0, x = 0, y = 0, dist = 0, q_size = 0;
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
      return -1;
    vector<pair<int, int>> dirs = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                                   {1, 0},  {1, -1}, {0, -1}, {-1, -1}};
    queue<pair<int, int>> Q;
    pair<int, int> cur;
    Q.push({0, 0});
    grid[0][0] = 1;

    while (Q.size()) {
      q_size = Q.size();
      ++dist;

      while (q_size--) {
        cur = Q.front();
        Q.pop();
        r = cur.first;
        c = cur.second;

        if (r == n - 1 && c == n - 1)
          return dist;

        for (auto &dir : dirs) {
          x = r + dir.first;
          y = c + dir.second;

          if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0) {
            Q.push({x, y});
            grid[x][y] = 1; // marking as visited here reduces redundant
                            // additions to the queue which prevents TLE
          }
        }
      }
    }

    return -1;
  }
};

auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
