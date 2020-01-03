#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/


int main()
{
    int L;
    cin >> L; cin.ignore();
    int N;
    cin >> N; cin.ignore();
    
    vector<pair<int, int> > a, b;
    
    for (int i = 0; i < N; i++) {
        int st;
        int ed;
        cin >> st >> ed; cin.ignore();
        a.push_back({min(st, ed), max(st, ed)});
    }
    
    sort(a.begin(), a.end());
    
    int f = a[0].first;
    int s = a[0].second;
    
    
    for(int i=1; i<a.size(); ++i) {
        if(f < a[i].first && s < a[i].first) {      // dosjoint range
            b.push_back({f, s});
            f = a[i].first;
            s = a[i].second;
        }
        else if(f <= a[i].first && s < a[i].second) { // overlapping range
            s = a[i].second;
        }
    }
    
    if(f == 0 && s == L) {
        cout<<"All painted";
        return 0;
    }
    
    b.push_back({f, s});
    
    int st = 0;
    
    for(auto c : b) {
        if(c.first != st) cout<<st<<" "<<c.first<<"\n";
        st = c.second;
    }
    
    if(L != st) cout<<st<<" "<<L<<"\n";

}