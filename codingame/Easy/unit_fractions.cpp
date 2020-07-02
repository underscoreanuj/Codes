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
    size_t n;
    cin >> n; cin.ignore();

    size_t n_sq = n*n, a=0, b=0;
    
    for(size_t i=1; i<=n; ++i) {
        
        if(n_sq%i != 0) continue;
        
        a = i;
        b = n_sq/i;
        
        cout << "1/"<<n<<" = 1/"<<b+n<<" + 1/"<<a+n<< endl;
    }
    
}