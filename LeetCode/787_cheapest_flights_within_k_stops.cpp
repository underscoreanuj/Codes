// simple bellman ford

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        vector<int> cost(n, 1000001);
        cost[src] = 0;

        for (int i = 0; i <= K; ++i)
        {
            vector<int> c(cost);
            for (auto &f : flights)
                c[f[1]] = min(c[f[1]], cost[f[0]] + f[2]);
            cost = c;
        }

        return cost[dst] == 1000001 ? -1 : cost[dst];
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// priority queue solution  (dijkstras)

typedef tuple<int, int, int> tup;
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        vector<vector<pair<int, int>>> graph(n);
        for (auto &f : flights)
            graph[f[0]].emplace_back(f[1], f[2]);

        priority_queue<tup, vector<tup>, greater<tup>> PQ;
        PQ.emplace(0, K, src);
        int cost, stops, cur;

        while (!PQ.empty())
        {
            auto [cost, stops, cur] = PQ.top();
            PQ.pop();

            if (cur == dst)
                return cost;
            if (stops >= 0)
            {
                for (auto d : graph[cur])
                {
                    PQ.emplace(cost + d.second, stops - 1, d.first);
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