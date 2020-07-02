#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

unordered_map<int, list<int>> adj;
unordered_map<int, pair<bool, int>> mem;
unordered_set<int> vert;

int dfs(int src)
{
    if (adj[src].size() == 0)
        return 0;
    if (mem[src].first)
        return mem[src].second;

    int max_depth = 0;
    auto it = adj[src].begin();
    for (; it != adj[src].end(); ++it)
    {
        max_depth = max(max_depth, 1 + dfs(*it));
    }

    mem[src] = {true, max_depth};

    return max_depth;
}

int main()
{
    int n; // the number of relationships of influence
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        int x; // a relationship of influence between two people (x influences y)
        int y;
        cin >> x >> y;
        cin.ignore();
        x;
        y;
        vert.insert(x);
        vert.insert(y);
        adj[x].push_back(y);
        if (mem.find(x) == mem.end())
            mem.insert({x, {false, 0}});
        if (mem.find(y) == mem.end())
            mem.insert({y, {false, 0}});
    }

    int max_ct = 0;
    for (auto e : vert)
    {
        max_ct = max(max_ct, dfs(e));
    }

    cout << max_ct + 1;
}