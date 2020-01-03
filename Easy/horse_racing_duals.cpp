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
    int N;
    cin >> N; cin.ignore();
    
    long long int * arr = new long long int[N];
    
    for (int i = 0; i < N; i++) {
        // int Pi;
        cin >> arr[i]; cin.ignore();
        
    }
    
    sort(arr, arr+N);
    
    long long int min_dist=1e9;
    for(int i=0; i<N-1; ++i) {
        min_dist = min(min_dist, abs(arr[i] - arr[i+1]));
    }

    cout << min_dist << endl;
}