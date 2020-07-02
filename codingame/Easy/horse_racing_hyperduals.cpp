#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
size_t getDistance(pair<int, int> h1, pair<int, int> h2) {
    return abs(h2.first - h1.first) + abs(h2.second - h1.second);
}

int main()
{
    int N;
    cin >> N; cin.ignore();
    
    vector<pair<int, int> > horses;
    
    for (int i = 0; i < N; i++) {
        int V;
        int E;
        cin >> V >> E; cin.ignore();
        horses.push_back({V, E});
    }
    
    size_t min_dist = 1e9+9;
    
    for(int i=0; i<N; ++i) {
        for(int j=i+1; j<N; ++j) {
            min_dist = min(min_dist, getDistance(horses[i], horses[j]));
        }
    }
    
    cout<<min_dist<<"\n";
    
}