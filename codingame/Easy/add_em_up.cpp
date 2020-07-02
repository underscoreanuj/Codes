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

int main()
{
    int N;
    cin >> N; cin.ignore();
    
    priority_queue<int, vector<int>, greater<int>> cards;
    
    int c;
    for (int i = 0; i < N; i++) {
        cin >> c; cin.ignore();
        cards.push(c);
    }
    
    int sum=0, total_sum = 0;
    
    while(!cards.empty()) {
        if(!cards.empty()) {
            sum = cards.top();
            cards.pop();
        }
        if(!cards.empty()) {
            sum += cards.top();
            cards.pop();
        }
        
        total_sum += sum;
        
        if(cards.empty()) break;
        
        cards.push(sum);
    }
    
    cout<<total_sum<<"\n";
    
}