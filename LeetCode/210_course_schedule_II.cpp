// dfs solution time: O(N), space: O(N)

class Solution
{
public:
    bool dfs(vector<vector<int>> &graph, vector<int> &status, vector<int> &result, int src)
    {
        if (status[src] == 0)
            return false;
        if (status[src] == 1)
            return true;

        status[src] = 0;
        for (int &dest : graph[src])
        {
            if (!dfs(graph, status, result, dest))
                return false;
        }
        status[src] = 1;
        result.emplace_back(src);

        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> result;
        vector<vector<int>> graph(numCourses);
        vector<int> status(numCourses, -1);

        for (auto &p : prerequisites)
        {
            graph[p[1]].emplace_back(p[0]);
        }

        for (int i = 0; i < numCourses; ++i)
        {
            if (status[i] == -1 && !dfs(graph, status, result, i))
                return {};
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

// bfs solution (without queue) time: O(V+E), space: O(V+E)

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> result;
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (auto &prereq : prerequisites)
        {
            graph[prereq[1]].emplace_back(prereq[0]);
            ++inDegree[prereq[0]];
        }

        for (int i = 0; i < inDegree.size(); ++i)
            if (inDegree[i] == 0)
                result.emplace_back(i);

        for (int i = 0; i < result.size(); ++i)
        {
            for (int &d : graph[result[i]])
                if (--inDegree[d] == 0)
                    result.emplace_back(d);
        }

        return result.size() == numCourses ? result : vector<int>();
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();