#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int M;
    cin >> M; cin.ignore();
    
    vector<double> data;
    double sum = 0, n_60 = 0, x = 0;
    
    for (int i = 0; i < M; i++) {
        for(int j=0; j<15; ++j) {
            cin>>x;
            data.push_back(x);
            sum += x;
        }
        n_60 += 10.0 + (sum - 40.0)/7.0;
        sum = 0;
    }
    
    n_60 /= (double)M;
    
    cout<<fixed<<setprecision(1)<<n_60<<"\n";
    
    if(n_60 >= 5 && n_60 <= 30) {
        double n_8 = 0;
        int len = data.size();
        len = (len%2 == 0) ? len : len-1;
        
        for(int i=0; i<len; i++) {
            n_8 += data[i];
        }
        
        len /= 2;
        
        n_8 += 5.0*(double)len;
        n_8 /= ((double)len);

        cout<<fixed<<setprecision(1)<<n_8<<"\n";
    }

}