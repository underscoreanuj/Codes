#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int R;
    cin >> R; cin.ignore();
    int V;
    cin >> V; cin.ignore();
    
    vector<pair<int, int> > vaults;
    
    for (int i = 0; i < V; i++) {
        int C;
        int N;
        cin >> C >> N; cin.ignore();
        vaults.push_back({N, C-N});
    }
    
    int digit_ct = 10, vowel_ct = 5;
    int res = 0;
    int idx = R <= V ? R : V;
    int real_time = 0;
    
    priority_queue<int, vector<int>, greater<int> > pq;
    
    for(int i=0; i<idx; ++i) {
        pq.push(pow(digit_ct, vaults[i].first) * pow(vowel_ct, vaults[i].second));
        --V;
    }
    
    
    while(V) {
        
        if(idx >= vaults.size()) break;
        
        int tmp = pq.top();
        pq.pop();
        
        tmp += pow(digit_ct, vaults[idx].first) * pow(vowel_ct, vaults[idx].second);
        pq.push(tmp);
        
        --V;
        ++idx;
    }
    
    
    while(!pq.empty()) {
        res = pq.top();
        pq.pop();
    }
    
    cout << res << endl;
}