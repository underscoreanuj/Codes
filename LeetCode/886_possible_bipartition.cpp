// bfs solution

class Solution
{
public:
    bool possibleBipartitionUtil(vector<vector<int>> &graph, vector<int> &colors, int src)
    {
        colors[src] = 0;
        queue<int> Q;
        Q.push(src);

        while (!Q.empty())
        {
            src = Q.front();
            Q.pop();

            for (int &dis : graph[src])
            {
                if (colors[dis] == colors[src])
                    return false;
                if (colors[dis] == -1)
                    Q.push(dis);
                colors[dis] = !colors[src];
            }
        }

        return true;
    }

    bool possibleBipartition(int N, vector<vector<int>> &dislikes)
    {
        vector<vector<int>> graph(N + 1);
        vector<int> colors(N + 1, -1);

        for (auto d : dislikes)
        {
            graph[d[0]].emplace_back(d[1]);
            graph[d[1]].emplace_back(d[0]);
        }

        for (int i = 1; i <= N; ++i)
        {
            if (colors[i] == -1 && !possibleBipartitionUtil(graph, colors, i))
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

// dfs solution

class Solution
{
public:
    bool possibleBipartitionUtil(vector<vector<int>> &graph, vector<int> &colors, int src, bool col)
    {
        colors[src] = col;

        for (int &dest : graph[src])
        {
            if (colors[dest] != -1 && colors[dest] == col)
                return false;
            if (colors[dest] == -1 && !possibleBipartitionUtil(graph, colors, dest, !col))
                return false;
        }

        return true;
    }

    bool possibleBipartition(int N, vector<vector<int>> &dislikes)
    {
        vector<vector<int>> graph(N + 1);
        vector<int> colors(N + 1, -1);

        for (auto d : dislikes)
        {
            graph[d[0]].emplace_back(d[1]);
            graph[d[1]].emplace_back(d[0]);
        }

        for (int i = 1; i <= N; ++i)
        {
            if (colors[i] == -1 && !possibleBipartitionUtil(graph, colors, i, 0))
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