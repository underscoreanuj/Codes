#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
bool vis[100007] = {false};
 
int getDigitSum(int x){
    return x ? x%10 + getDigitSum(x/10) : 0;
}
 
bool isPartOfRiver(int r, int p) {
    
    while(r <= p) {
        if(vis[r]) return false;
        vis[r] = true;
        if(r == p) return true;
        r += getDigitSum(r);
    }
    
    return false;
}

int main()
{
    int r1;
    cin >> r1; cin.ignore();
    
    bool flag = false;
    
    for(int i=1; i<r1; ++i) {
        if(!vis[i] && isPartOfRiver(i, r1)) {
            flag = true;
            break;
        }
    }

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}