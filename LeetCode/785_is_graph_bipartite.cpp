// dfs solution

class Solution {
public:
  bool isBipartiteUtil(vector<vector<int>> &graph, vector<int> &vis, int src,
                       int color = 1) {
    vis[src] = color;
    bool result = true;

    for (int &nxt : graph[src]) {
      if (vis[nxt] == 0 && isBipartiteUtil(graph, vis, nxt, -color) == false)
        return false;
      else if (vis[nxt] != 0 && vis[nxt] == color)
        return false;
    }

    return result;
  }

  bool isBipartite(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> vis(n, 0);

    for (int i = 0; i < n; ++i) {
      if (vis[i] == 0 && isBipartiteUtil(graph, vis, i) == false)
        return false;
    }

    return true;
  }
};

auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();

// bfs solution

class Solution {
public:
  bool isBipartite(vector<vector<int>> &graph) {
    int n = graph.size(), cur = 0, q_size = 0, color = 1;
    vector<int> vis(n, 0);

    for (int i = 0; i < n; ++i) {
      if (vis[i] == 0) {
        queue<int> Q;
        Q.push(i);
        color = 1;

        while (Q.size()) {
          q_size = Q.size();
          color = -color;

          while (q_size--) {
            cur = Q.front();
            Q.pop();

            vis[cur] = color;
            for (int &nxt : graph[cur]) {
              if (vis[nxt] == 0)
                Q.push(nxt);
              else if (vis[nxt] == color)
                return false;
            }
          }
        }
      }
    }

    return true;
  }
};

auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
