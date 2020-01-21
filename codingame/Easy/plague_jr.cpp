#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int N;

int bfs(int src, vector<int> g[]) {
    queue<int> Q;
    Q.push(src);
    
    vector<bool> vis(N+1, false);
    
    int ct = -1;
    
    while(!Q.empty()) {
        int q_size = Q.size();
        
        for(int i=0; i<q_size; ++i) {
            int tmp = Q.front();
            Q.pop();
            vis[tmp] = true;
            
            for(int j=0; j<g[tmp].size(); ++j) {
                if(!vis[g[tmp][j]]) {
                    Q.push(g[tmp][j]);
                }
            }
        }
        
        ++ct;
    }
    
    return ct;
}

int main()
{
    cin >> N; cin.ignore();
    
    vector<int> g[N+1];
    
    for (int i = 0; i < N; i++) {
        int A;
        int B;
        cin >> A >> B; cin.ignore();
        g[A].push_back(B);
        g[B].push_back(A);
    }
    
    int min_days = 999999;
    
    for(int i=0; i<N; ++i) {
        min_days = min(min_days, bfs(i, g));
    }

    cout << min_days << endl;
}