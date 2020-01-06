#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/


int getInt(char c) {
    if(c >= '0' && c <= '9') return c - '0';
    return 0;
}

int getProcessedNum(char c) {
    int p = getInt(c)*2;
    return p > 9 ? p - 9 : p;
}

void validateCard(string card)  {
    int n = card.length();
    
    if(n != 19) {
        cout<<"NO\n";
        return;
    }
    
    int sum1 = 0, sum2 = 0, ct = 0;
    for(int i=n-2; i>=0; i-=2) {
        
        sum1 += getProcessedNum(card[i]);
        
        ++ct;
        if(ct%2 == 0) --i;
    }
    
    ct = 0;
    
    for(int i=n-1; i>=1; i-=2) {
        
        sum2 += getInt(card[i]);
        
        ++ct;
        if(ct%2 == 0) --i;
    }
    
    if((sum1+sum2)%10 == 0) cout<<"YES\n";
    else cout<<"NO\n";
    
}


int main()
{
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string card;
        getline(cin, card);
        
        validateCard(card);
    }

}