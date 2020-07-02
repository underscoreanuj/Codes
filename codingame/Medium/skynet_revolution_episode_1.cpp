#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <list>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int N; // the total number of nodes in the level, including the gateways
int L; // the number of links
int E; // the number of exit gateways

void bfs(int src, vector<list<int>> &g, unordered_set<int> gw, int &start, int &end)
{
    queue<int> Q;
    Q.push(src);
    vector<bool> vis(N, false);

    while (!Q.empty())
    {
        int sz = Q.size();
        for (int i = 0; i < sz; ++i)
        {
            int s = Q.front();
            Q.pop();
            vis[s] = true;

            auto it = g[s].begin();
            for (; it != g[s].end(); ++it)
            {
                if (gw.find(*it) != gw.end())
                {
                    start = s;
                    end = *it;
                    g[s].erase(it); // sever the link
                    return;
                }
                if (!vis[*it])
                    Q.push(*it);
            }
        }
    }
}

int main()
{
    cin >> N >> L >> E;
    cin.ignore();

    vector<list<int>> G(N);
    unordered_set<int> gateway;

    for (int i = 0; i < L; i++)
    {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2;
        cin.ignore();
        G[N1].push_back(N2);
        G[N2].push_back(N1);
    }
    for (int i = 0; i < E; i++)
    {
        int EI; // the index of a gateway node
        cin >> EI;
        cin.ignore();
        gateway.insert(EI);
    }

    // game loop
    int x, y;
    while (1)
    {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI;
        cin.ignore();

        x = y = 0;
        bfs(SI, G, gateway, x, y);

        cout << x << " " << y << endl;
    }
}