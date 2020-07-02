#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/


double getWork(int level, int weight) {
    return ((level-1)*6.5/100)*10*weight;
}

int main()
{
    int X;
    cin >> X; cin.ignore();
    int N;
    cin >> N; cin.ignore();
    
    vector<int> bricks(N, 0);
    
    for (int i = 0; i < N; i++) {
        cin >> bricks[i]; cin.ignore();
    }
    
    sort(bricks.begin(), bricks.end(), greater<int>());
    
    double work = 0;
    int level = 1;
    int ct = 0;
    
    for(int i=0; i<N; ++i) {
        work += getWork(level, bricks[i]);
        ++ct;
        
        if(ct == X) {
            ct = 0;
            ++level;
        }
    }
    
    printf("%.3f", work);
}