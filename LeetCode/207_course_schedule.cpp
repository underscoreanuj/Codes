// bfs solution (topological sort solution)  time : O(N + E), using queue

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (auto &p : prerequisites)
        {
            graph[p[1]].emplace_back(p[0]);
            ++inDegree[p[0]];
        }

        queue<int> order;
        int cur = 0;

        for (int i = 0; i < inDegree.size(); ++i)
            if (inDegree[i] == 0)
                order.push(i);

        while (!order.empty())
        {
            cur = order.front();
            order.pop();

            for (int d : graph[cur])
                if (--inDegree[d] == 0)
                    order.push(d);
        }

        return accumulate(inDegree.begin(), inDegree.end(), 0) == 0;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// bfs solution (topological sort solution)  time : O(N + E), without using queue

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (auto &p : prerequisites)
        {
            graph[p[1]].emplace_back(p[0]);
            ++inDegree[p[0]];
        }

        vector<int> order;
        for (int i = 0; i < inDegree.size(); ++i)
            if (inDegree[i] == 0)
                order.emplace_back(i);
        for (int i = 0; i < order.size(); ++i)
            for (int &d : graph[order[i]])
                if (--inDegree[d] == 0)
                    order.emplace_back(d);

        return order.size() == numCourses;
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
    bool dfs(vector<vector<int>> &graph, vector<bool> &seen, int src)
    {
        if (seen[src])
            return false;

        seen[src] = true;

        for (int &dest : graph[src])
        {
            if (!dfs(graph, seen, dest))
                return false;
        }

        seen[src] = false;

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<bool> seen(numCourses, false);

        for (auto &p : prerequisites)
        {
            graph[p[1]].emplace_back(p[0]);
        }

        for (int i = 0; i < numCourses; ++i)
        {
            if (!seen[i] && !dfs(graph, seen, i))
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